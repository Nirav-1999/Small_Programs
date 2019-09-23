#include<stdio.h>

void merge(int a[10],int beg,int mid,int end){
    int i =beg, j =mid+1 ,temp[10], count = beg;
    while(i<=mid && j<=end){
        if (a[i]<a[j]) {
            temp[count] = a[i];
            i++;
        }
        else
        {
            temp[count] = a[j];
            j++; 
        }
        count++;
    }
    if(i>mid){
        while(j<=end){
            temp[count] = a[j];
            j++;
            count++;
        }
    }
    else{
        while(i<=mid){
            temp[count] = a[i];
            i++;
            count++;
        }
    }
    for(i = beg; i < count; i++)
    {
        a[i] = temp[i];
    }
    
    
}

void merge_sort(int a[10],int beg,int end){
    int mid;

    if (beg<end) {
        mid = (beg + end)/2;
        merge_sort(a,beg,mid);
        merge_sort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
    
    
}

void main(){
    int a[10] = {22,13,45,26,78,34,24,14,556,9};
    int n = 10,i;
    merge_sort(a,0,n);
    for(i = 0; i < n; i++)
    {
        printf("%d\n",a[i]);
    }
    
}