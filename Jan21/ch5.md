This section is more practical 
	1. Fork() system call -- most strange system call 产生一个一摸一样的子进程
The fork system call is used to create a new process. For example, 
	2. Wait()   等待子进程结束再运行父进程
Sometimes it is quite useful for a parent to wait for a child process to finish what it has been doing. This task is accomplished with the wait() system call . 

	3. Exec system call  偷梁换柱，执行某一个进程
This system call is useful when you want to run a program that is diferent from the calling program. 
Given the name of an executable and some arguments, it loads code and static data from that executable and overwrites its current code segment and current static data with it the heap and stack and other parts of the memory space of the program are re-initialized.  

	4. Why APIS?
Call fork to create a new child process to run the command, 
Call some variant of exec() to run the command,
and then waits for the cmmand to complete by calling wait().  
