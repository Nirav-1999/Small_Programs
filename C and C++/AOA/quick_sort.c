#include<stdio.h>

int partition(int a[10],int beg,int end){
    int loc = beg,left = beg,right = end,flag = 0,temp;
    while(flag != 1){
        while(a[right]>a[loc] && right!=loc){
            right--;
        }
        if(right == loc){
            flag = 1;
        }
        else if(a[right]<a[loc]){
            temp = a[right];
            a[right] = a[loc];
            a[loc] = temp;
            loc = right;
        }
        if(flag!=1){
            while(a[left]<a[loc] && left!=loc){
                left++;
            }
            if(left == loc){
            flag = 1;
            }
            else if(a[left]>a[loc]){
                temp = a[left];
                a[left] = a[loc];
                a[loc] = temp;
                loc = left;
            }
        }
    }
    return loc;

}

void quick_sort(int a[10],int beg,int end){
    int loc;

    if (beg<end) {
        loc = partition(a,beg,end);
        quick_sort(a,beg,loc-1);
        quick_sort(a,loc+1,end);

    }
    
    
}

void main(){
    int a[10] = {22,13,45,26,78,34,24,14,556,9};
    int n = 10,i;
    quick_sort(a,0,n);
    for(i = 0; i < n; i++)
    {
        printf("%d\n",a[i]);
    }
    
}