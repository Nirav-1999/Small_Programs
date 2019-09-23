#include<bits/stdc++.h>
using namespace std;

long long Queries (vector<int> A, int K) {
    int X;
   for (int i = 0; i < A.size(); i++)
    {
        X = 0;
        for (int j = i; j < A.size(); j++)
        {
            if(X+A[j] > K){
                break;
            }
            X += A[j];

        }

        A[(i+X)%A.size()] = K ^ X;
        
    }
    X = 0;
    for (int i = 0; i < A.size(); i++)
    {
        X += A[i];
        cout<<"\n"<<A[i];
    }
   
   return X;
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i_A=0; i_A<N; i_A++)
    {
    	cin >> A[i_A];
    }

    long long out_;
    out_ = Queries(A, K);
    cout << out_;
}