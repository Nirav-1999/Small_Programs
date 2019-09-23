// Our Battlestarcraft Algorithmica ship is being chased through space by persistent robots called Pylons! We have just teleported to a new galaxy to try to shake them off of our tail, and we want to stay here for as long as possible so we can buy time to plan our next move... but we do not want to get caught!

// This galaxy is a flat grid of R rows and C columns; the rows are numbered from 1 to R from top to bottom, and the columns are numbered from 1 to C from left to right. We can choose which cell to start in, and we must continue to jump between cells until we have visited each cell in the galaxy exactly once. That is, we can never revisit a cell, including our starting cell.

// We do not want to make it too easy for the Pylons to guess where we will go next. Each time we jump from our current cell, we must choose a destination cell that does not share a row, column, or diagonal with that current cell. Let (i, j) denote the cell in the i-th row and j-th column; then a jump from a current cell (r, c) to a destination cell (r', c') is invalid if and only if any of these is true:

// r = r'
// c = c'
// r - c = r' - c'
// r + c = r' + c'
// Can you help us find an order in which to visit each of the R × C cells, such that the move between any pair of consecutive cells in the sequence is valid? Or is it impossible for us to escape from the Pylons?




#include<iostream>
#include<math.h>

using namespace std;

void pos_place(int k,int r, int c, int phases[10], int states[10], int sum, int max);
int place(int r,int c, int phases[10], int states[10]);
// int count = 0;
int ans[20][2];
int a[20][20],t,phases[10],states[10];
int flag;
int main(){
	int r,c,sum1=0,sum2=0,sum,max1=0,max2=0,max,count = 0;
    cin>>r;
    cin>>c;
    flag = 0;
    for (int i = 0; i < r; i++)
    {
        cin>>phases[i];
        sum1 += phases[i];
        if(max1<phases[i]){
            max1 = phases[i];
        }
    }
    for (int i = 0; i < c; i++)
    {
        cin>>states[i];
        sum2 += states[i];
        if(max2<phases[i]){
            max2 = phases[i];
        }
    }
    if(sum1>sum2){
        sum = sum1;
        max = max1;
    }
    else{
        sum = sum2;
        max = max2;
    }

    pos_place(0,r,c,phases,states,sum,max*r);
    if(flag==0){
        cout<<"NO\n";
    }
	
	
	return 0;
}

void pos_place(int k ,int r, int c, int phases[10], int states[10], int sum, int max){

	int i;
	for(i=0; i<c; i++){
		if(flag ==1){
	        return;
	    }
        cout<<"----->"<<sum<<"<---("<<k<<","<<i<<")---\n";

		if (place(k,i,phases,states)){
			// a[k][i]=1;
            sum--;
            phases[k]--;
            states[i]--;
            if(sum == 0){
                cout<<"YES";
                flag = 1;
            }

			else{
				pos_place((k+1)%r,r,c,phases,states,sum,max--);
				sum++;
                phases[k]=0;
                states[i]=0;
				// a[k][i]=0;
				
			}
		}

	}
    if (max>0)
    {
        pos_place((k+1)%r,r,c,phases,states,sum,max--);
    }
    


}

int place(int r, int c, int phases[10], int states[10]){
	if(phases[r]>0 && states[c]>0){
        return 1;
    }
    return 0;
}