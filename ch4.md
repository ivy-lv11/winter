1. Definition of  process: a process is simply a running proram.运行的程序叫做进程

2. 进程的组成：
We have to know machine state:address space/registers/special registers(pc,esp,ebp etc)/persistent storage devices (IO) 

3.进程API
Create:当你双击图标或者在命令行shell里输入命令，创建新的进程
Destroy：结束进程
Wait
Miscellaneous control：suspend the process and then resume it。先暂停一个进程的运行，然后过一会再运行它。
Status

4.process creation: OS如何创建一个进程？
首先要把只读代码区和可读写数据区加载到内存中,（PA实现的loader）。然后构建运行时的栈和堆。最后找到entry point，pc转到entry point，控制由OS到进程，开始该进程的执行。

5.process states进程状态
	• 就绪 ready:a process is ready to run but for sume reason the OS has chosen not to run it at this given moment. 
	• 运行running :  aprocess is running on a processor this means it is executing instructions. 
	• 阻塞blocked: a process has performed some kind of operations that makes it not ready to run until some other event takes place. 进程处于阻塞状态时，即使把CPU给该进程，进程也无法运行。要等到特定事件完成，才能把阻塞变成ready就绪。
	• 创建：进程正在被创建，尚未到就绪状态。
	• 结束
判断ready和blocked：关键在于给处理器能不能立即运行，若能是ready，否则是blocked。

6.进程状态的相互转化：
Ready - runnning    schedule/deschedule  进程调度
Running -> blocked   等待事件
Blocked -> ready 满足条件

7. 数据结构:PCB

8. 总结：
