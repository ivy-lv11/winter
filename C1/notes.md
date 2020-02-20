## Code lecture1笔记  
1.gcc -c a.c编译得到 a.o  
file a.o看文件类型 看到是relocatable可重定位目标文件    
ld a.o得到a,out，使用file看文件类型,是executable文件  
./a.out错误  
可以用vim看a.out，但是不可读，只能看到ELF  
也可用xxd读，可以看到对应的阿斯科编码 
解析ELF最好用readelf读，关注entry point/program section   
启发：main()是由操作系统调用的，如果直接链接返回地址错误  

2.应用程序到底如何调用操作系统？  
失败尝试1的原因：undefined reference to puts没有C库函数  
失败尝试2的原因：（ld -e main hello.o）
用gdb去看一下：  
<tips starti从第一条指令开始执行  
layout src看源代码  
layout asm看汇编  
info register看寄存器  
bt看堆栈  
!pmap[pid] 看映射  
info inferiors  
>

以minimal.S为例  
gcc -c minimal.S  
ld -e foo minimal.o
//产生a.out
./a.out
正确执行

使用gdb追踪过程  
gdb a.out  
starti  
si单步执行  
可以看到有两个syscall，对应write,exit  

3.以Csyscal-demo为例  
gdb syscall  
starti  
这时看到ld-linux-x86-64.so.2这是内核调用操作系统的部分，所以第一条指令不是从main开始的  
想看代码？objdump！
gdb中用info inferiors/!pmap [pid]  

4.hello-goodby例子  
strace ./hello-goodby  

5.xedit看图形界面  
strace xedit  

 
