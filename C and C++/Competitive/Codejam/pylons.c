// Our Battlestarcraft Algorithmica ship is being chased through space by persistent robots called Pylons! We have just teleported to a new galaxy to try to shake them off of our tail, and we want to stay here for as long as possible so we can buy time to plan our next move... but we do not want to get caught!

// This galaxy is a flat grid of R rows and C columns; the rows are numbered from 1 to R from top to bottom, and the columns are numbered from 1 to C from left to right. We can choose which cell to start in, and we must continue to jump between cells until we have visited each cell in the galaxy exactly once. That is, we can never revisit a cell, including our starting cell.

// We do not want to make it too easy for the Pylons to guess where we will go next. Each time we jump from our current cell, we must choose a destination cell that does not share a row, column, or diagonal with that current cell. Let (i, j) denote the cell in the i-th row and j-th column; then a jump from a current cell (r, c) to a destination cell (r', c') is invalid if and only if any of these is true:

// r = r'
// c = c'
// r - c = r' - c'
// r + c = r' + c'
// Can you help us find an order in which to visit each of the R × C cells, such that the move between any pair of consecutive cells in the sequence is valid? Or is it impossible for us to escape from the Pylons?




#include<stdio.h>
#include<math.h>

void pos_place(int k,int n,int r, int c, int last_i,int last_j,int count);
int place(int r,int c, int last_i, int last_j);
// int count = 0;
int ans[20][2];
int a[20][20],t;
flag = 0;
void main(){
	int r,c,n,i,j,T;
	scanf("%d",&T);
	for(t = 1; t <= T; t++)
	{	
		flag = 0;
		scanf("%d %d",&r,&c);
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				a[i][j]=0;
			}
		}
		pos_place(0,r*c,r,c,99,99,0);
		if(flag==0){
			printf("Case #%d: IMPOSSIBLE\n",t);
		}
	}
	
	
}

void pos_place(int k ,int n,int r, int c, int last_i,int last_j,int count){

	int i;
	for(i=0; i<c; i++){
		if(flag ==1){
	        return;
	    }
		if (place(k,i,last_i,last_j) && a[k][i]!=1){
			a[k][i]=1;
			ans[count][0]=k;
			ans[count][1]=i;
			if (count+1 == n){
				if(flag==0){
					flag=1;
					printf("Case #%d: POSSIBLE",t);
					for(int x = 0; x < n; x++)
					{
						printf("\n%d %d",ans[x][0]+1,ans[x][1]+1);
					}
					printf("\n");
					}
				}
			else{
				pos_place((k+1)%r,n,r,c,k,i,++count);
				count--;
				a[k][i]=0;
				
			}
		}
	}	


}

int place(int r, int c, int last_i, int last_j){
	if(last_i==99){
		return 1;
	}
	if(r==last_i || c==last_j || r+c == last_i + last_j || abs(r-c) == abs(last_j-last_i)){
		return 0;
	}
	return 1;
}