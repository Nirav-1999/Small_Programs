// Implement Shortest Job First (Preemptive) algorithm

#include<stdio.h>

void sort(int a[10],int b[10],int c[10], int n){
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
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
        }
        
    }
    
}

void main(){
    int no_proc,bt[10],at[10],rt[10],i,j,k,avg_tat=0,avg_wt=0,remaining,count=0,t=0,min=999,pos,check=1,p[10];
    float wt = 0,tat=0;
    printf("Enter the number of processes\n");
    scanf("%d",&no_proc);
    remaining = no_proc;
    for (i = 0; i < no_proc; i++)
    {
        printf("Enter the arrival time, burst time and priority for P%d\t",i+1);
        scanf("%d",&at[i]);
        scanf("%d",&bt[i]);
        scanf("%d",&p[i]);
        rt[i] = bt[i];
    }
    sort(at,p,bt,no_proc);
    // for(i=0;i<no_proc;i++){
    //     printf("%d\tP%d\n",at[i],i+1);
    // }
    printf("Process\tArrivalTime\tPriority\tBurstTime\tWaitingTime\tTurnaroundTime\n");
    while(remaining!=0){
        for ( j = 0; j < no_proc; j++)
        {
            if(at[j]<=t && p[j]<min &&rt[j]>0){
                min = p[j];
                pos = j;
                check = 0;
            }
        }
        if(check == 1){
            t++;
            continue;
        }
        rt[pos]--;
        // printf("%d->P%d\n",t,pos+1);

        if(rt[pos]==0){
            min = 999;
            remaining--;
            check = 1   ;
            printf("P%d     \t%d          \t%d       \t%d        \t%d          \t%d\t%d\n",pos+1,at[pos],p[pos],bt[pos],t-at[pos]-bt[pos]+1,t-at[pos]+1,t+1);
            wt += t-at[pos]-bt[pos]+1;
            tat += t-at[pos]+1;
        }
        t++;

        
    }

    printf("Average waiting time = %f\n",(float)(wt/no_proc));
    printf("Average turnaround time = %f\n",(float)(tat/no_proc));
    
}
