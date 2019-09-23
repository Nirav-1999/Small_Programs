// Implement Shortest Job First (Preemptive) algorithm

#include<stdio.h>

void sort(int a[10],int b[10], int n){
    int i,j,temp;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < i; j++)
        {
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] =temp;
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
        
    }
    
}

void main(){
    int no_proc,pr[10],at[10],rt[10],wt = 0,tat=0,i,j,k,avg_tat=0,avg_wt=0,remaining,count=0,t=0,min=999,pos,check=1;
    printf("Enter the number of processes\n");
    scanf("%d",&no_proc);
    remaining = no_proc;
    for (i = 0; i < no_proc; i++)
    {
        printf("Enter the arrival time and burst time for P%d\t",i+1);
        scanf("%d",&at[i]);
        scanf("%d",&pr[i]);
        rt[i] = pr[i];
    }
    sort(at,pr,no_proc);
    // for(i=0;i<no_proc;i++){
    //     printf("%d\tP%d\n",at[i],i+1);
    // }
    printf("Process\tArrivalTime\tBurstTime\tWaitingTime\tTurnaroundTime\n");
    while(remaining!=0){
        for ( j = 0; j < no_proc; j++)
        {
            if(at[j]<=t && rt[j]<min &&rt[j]>0){
                min = rt[j];
                pos = j;
                check = 0;
            }
        }
        if(check == 1){
            t++;
            continue;
        }
        rt[pos]--;
        t++;
        min = rt[pos];
        if(min==0){
            min = 999;
        }
        if(rt[pos]==0){
            remaining--;
            check = 1   ;
            printf("P%d     \t%d          \t%d        \t%d          \t%d\n",pos+1,at[pos],pr[pos],t-at[pos]-pr[pos],t-at[pos]);
            wt += t-at[pos]-pr[pos];
            tat += t-at[pos];
        }

        
    }

    printf("Average waiting time = %d\n",wt/no_proc);
    printf("Average turnaround time = %d\n",tat/no_proc);
    
}
