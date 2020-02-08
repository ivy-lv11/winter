	1. Basic idea: run one process for a little while , then run another one, and so forth. By time sharing CPU in this manner,  virtualization is achieved. 运行一会A， 再运行一会B，如此反复。
	2. Question:
	• Performance: 实现虚拟化，且不需要付出太多额外代价.
	• Control: retain control over CPU. 
	3. Basic technique: limited direct execution
The direct execution part of the idea is simple:just run the program directly on the CPU. 直接在CPU上运行程序.when the Oswidhes to start a program running it creates a process entry for ir in a process list, allocates some memory for it, loads the proram code into memory, lodates its entry point routine or something similar, jumps to ir and starts running the user's code.创建进程，分配空间，加载，跳到entry point. 
Problem: 
	• How to guarantee the program does not do anything that wo don't want it to do. （越权/越级，主要是用户态和内核态的问题）
	• How to implement the time sharing？（分时，主要是时钟中断，上下文切换）
	4. 解决问题1  restricted operations
The approach we take is to introduce a new processor mode known as user mode. Code that runs in user mode is trstricted in what it can do. 用户态只能执行它被允许做的指令。
In contrast to user mode is kernel mode, which the operating system run in. 内核态，操作系统运行的状态。In this mode, code that runs can do what it likes , including privileged operations such as issuing IO requests and executing all types of restricted instructions. 内核态为所欲为，执行各式特权指令。
两者之间的桥梁：system call. To execute a system call, 
	• a program must execute a  special trap instruction, this instruction simultaneously jumps into the kernel and raises the privilege level to kernel mode; 通过自陷指令进入内核态，level到kernel mode
	• Once in the kernel , system can now perform whatever required work for the calling process. 进入内核之后，系统可以为所欲为。Hardware needs to be a bit careful when executing a trap, in that it must make sure to save enough of the caller's registers in order to be able to return correctly when the OS issues the return from trap instruction. 由硬件保存现场（寄存器状态）。
	• When finished , the os CALLS A SPECIL RETURN FROM TRAP instruction which returns into the calling user program while simultaneously reducing the privilege level back to user mode. 由特殊的iret指令返回到调用的用户程序，level回到用户态。
如何知道跳转到哪一个内核处理例程呢？The kernel does so by setting up a trap table at boot time. 
System call number is usually assugbed ti each system call.  User code is thos resposible for placing the desired system call number in a register or at a specified location on the stack; OS when handling the system call inside the trap handler, examines this number ensures it is valid, and if it is , executes the corresponding code. This level of indirection serves as a form of protection; user code cannot specify an exact address to jump to, but rather must request a paticular service via number. 
	5. 解决问题2 上下文切换
	• Cooperative approach: wait for system calls 等系统调用
Thus in a cooperative scheduling system,  the OS regains control of the CPU by waiting for a system call or  an illegal operation of some kind to take place.  Too passive. What if a process never ends up in an infinite loop and never makes a system call？
	• Non-cooperative approach: The OS takes control . 通过时钟中断，CPU获得控制权
A timer interrupt. 
A timer device can be programmed to raise an interrupt every so mane millseconds; ehwn the interrupt is raised, the currently running process is halted, and a preconfigured interrupt handler in the OS runs. At this point the OS regained control of the CPU, and thus can do what it pleases: stop the current process and start a different one. 时钟中断每多少毫秒一次，每到时钟中断，调用OS例程，OS获得控制权，它可以决定是否继续运行该程序。
Once the timer has begun ths OS can feel safe in that control will eventually be returned to it, and thus the OS is free to run user programs. 
	6. Saving and restoring context.
Save the GPRs ,PC(eip), kernel stack pointer of the currently-running process and restore said registers, pc, and switch to the kernel stack for the soon-to-be-executing process. 
	
	
