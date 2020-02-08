## scheduling 调度问题  
1. #### workload assumptions  
* each job runs for the same amount of time  
* all jobs arrive at the same time  
* once started, each job runs to completion  
* all jobs only use the cpu.   
* the run-time of each job is known.    

2. #### scheduling metrics  
Tturnaround = Tcompletion - Tarrival  

3. #### FIFO  
先进先出

4. #### relax assumption 1  
现在每项任务运行时间不等.SJF(shortest job first，耗时最少的先做)  
由贪心算法，assumption下SJF最优optimal.  

5. #### relax assumption 1,2
现在每个进程耗时不等，也不一定同时开始.  
To address this concern,we need to relax assumption 3 (每一项进程都运行到结束,relax之后每一项进程不一定要运行到结束)
#### STCF (shortest time to completion first 最短剩余时间最先)  
在这种假设下，STCF也是最优的.  

6. #### a new metric : response time
#### We define response time as the time from when the job arrives in a system to the first time it is scheduled.  
arrival到首次被调上CPU的时间.  

#### 7. round robin (RR algorithm time slicing)  
basic idea: instrad of running jobs to completion, RR runs a job for a time slice(sometimes called a scheduling quantum)  
and switches to the next job in the run queue. It repeatedly does so until the jobs are finished.  
*The first type(SJF,STCF) optimizes turnaround time, but is bad for response time. The second type RR optimizes response time but is bad for turnaround.It is a tradeoff. *  

8. relax assumption 4 (NO IO)  
considering IO

9. relax assumption 5 (know time cost)


