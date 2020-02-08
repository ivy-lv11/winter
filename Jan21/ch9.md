## ch9 proportional-share scheduler  
基础想法：guarantee each job obtain certain perentage of cpu time.  

* lottery scheduling  
every so often,hold a lottery to determine which process should goto run next; processes that should run more often should be given more chances to win the lottery. 

```
//counter: used to track if we have found the winner yet.
int counter = 0;
//winner : use some call to a random number generator to get a value, between 0 and totall f tickets
int winner = getrandom(0,totaltickets);

//current: use this to walk through the list of jobs
node_t *current = head;
while(current){
  counter = counter + current->tickets;
  if (counter>winner)
    break;
  current = current->next;
}
//current is the winner:schedule it. 

```  

* stride scheduling  
