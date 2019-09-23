// Implement Shortest Job First (Non-Preemptive) algorithm

#include<stdio.h>

void sort(int a[10], int n){
    int i,j,temp;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < i; j++)
        {
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] =temp;
            }
        }
        
    }
    
}

void main(){
    int no_proc,pr[10],wt = 0,tat=0,i,j,k,avg_tat=0,avg_wt=0;
    printf("Enter the number of processes\n");
    scanf("%d",&no_proc);
    for (i = 0; i < no_proc; i++)
    {
        printf("Enter the burst time for P%d\t",i+1);
        scanf("%d",&pr[i]);
    }
    sort(pr,no_proc);
    printf("Process\tBurstTime\tWaitingTime\tTurnaroundTime\n");
    for (i = 0; i < no_proc; i++)
    {
        tat = wt + pr[i];
        avg_tat+=tat;
        printf("P%d     \t%d        \t%d           \t%d\n",i+1,pr[i],wt,tat);
        if (i<no_proc-1)
        {
            wt += pr[i];
            avg_wt += wt;
        }
        
    }

    printf("Average waiting time = %d\n",avg_wt/no_proc);
    printf("Average turnaround time = %d\n",avg_tat/no_proc);
    
}
