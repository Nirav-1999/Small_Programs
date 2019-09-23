#include<bits/stdc++.h>
using namespace std;

long x = 0;
                //[0,0,0,40,20,60,80,done]  400     8       0            
long long overflow_packets (vector<int> A, int P, int N, int no) { 
    int rem,rem1,rem2;
    if((A[no]==0 && P>0) || no>=N){
        x += P;
        return x;             //x = 0
    }
    if(P>A[no]){
        rem = P - A[no];    //rem = 380 || 150 || 55
        A[no] = 0;    
        rem2 = rem/2;       //rem2 = 190 || 75 || 27
        rem1 = rem - rem2;  //rem1 = 190 || 75 || 28

        overflow_packets(A, rem1, N, 2*no+1); //(A,190,8,1) || (A,75,8,3) || (A,28,8,7) || (A,27,8,8)
        overflow_packets(A, rem2, N, 2*no+2);
        return x;
    }
    else
    {
        A[no] -= P;
        return 0;
    }
    
   
}



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    long P, N;
    cin >> P >> N;
    vector<int> A(N);
    for(int i_A=0; i_A<N; i_A++)
    {
    	cin >> A[i_A];
    }

    long long out_;
    out_ = overflow_packets(A, P, N, 0);
    cout << out_;
}