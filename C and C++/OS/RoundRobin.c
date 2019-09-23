// Implement RoundRobin algorithm

#include<stdio.h>

void main(){
    int no_proc,pr[10],wt = 0,tat=0,i=0,ts,flag=0,t=0,at[10],rt[10],remain,count = 0;
    printf("Enter the number of processes\n");
    scanf("%d",&no_proc);
    remain = no_proc;
    for (i = 0; i < no_proc; i++)
    {
        printf("Enter the burst time and arrival time for P%d\t",i+1);
        scanf("%d",&pr[i]);
        scanf("%d",&at[i]);
        rt[i] = pr[i];        
    }
    printf("Enter time slice\t");
    scanf("%d",&ts);
    printf("Process\tArrivalTime\tWaitingTime\tTurnaroundTime\n");
    while(remain!=0)
    {
        if(rt[count] <= ts && rt[count]>0){
            t += rt[count];
            rt[count] = 0;
            flag = 1;      
        }
        else if(rt[count]>0){
            t += ts;
            rt[count] -= ts;

        }
        if(rt[count] == 0 && flag == 1){
            remain--;
            printf("P%d     \t%d          \t%d          \t%d\n",count+1,at[count],t - at[count] - pr[count],t - at[count]);
            wt += t - at[count] - pr[count];
            tat += t - at[count];
            flag = 0;
        }


        if(count==no_proc-1){
            count=0;
        }
        else if (at[count+1]>=t)
        {
            count+=2;
        }
        
        else
        {
            count++;
        }


        
        
    }

    printf("Average waiting time = %d\n",wt/no_proc);
    printf("Average turnaround time = %d\n",tat/no_proc);
    
}