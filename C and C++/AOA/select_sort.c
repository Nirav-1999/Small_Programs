#include<stdio.h>

int smallest(int a[10],int k,int n){
    int i,min,pos;
    min = a[k];
    pos = k;
    for(i = k+1; i < n; i++)
    {
        if(a[i] < min){
            min = a[i];
            pos = i;
        }
    }
    return pos;
    
}

void select_sort(int a[10], int n){
    int i,small,temp;
    for(i = 0; i < n; i++) 
    {
        small = smallest(a,i,n);
        temp = a[i];
        a[i] = a[small];
        a[small] = temp;

    }

    for(i = 0; i < n; i++)
    {
        printf("%d\n",a[i]);
    }
    
    
    
}

void main(){
    int a[10] = {22,13,45,26,78,34,24,14,556,9};
    int n = 10;
    select_sort(a,n);
}