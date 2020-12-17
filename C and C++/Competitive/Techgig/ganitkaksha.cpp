#include<bits/stdc++.h>

using namespace std;

int get_no_divisors(int n){
    int a=0;
    float x;
    x = sqrt(n);
    for (int i = 1; i <= (int)x; i++)
    {
        if(n%i==0){
            a++;
        }
    }
    if(x==(int)x){
        a =2*a-1;
    }
    else{
        a = 2*a;
    }
    // cout<<"a="<<a<<"\n";
    return a;
}

int main(){
    long long int d,n,a,m;
    int flag=1;
    cin>>d;
    n = pow(2,d);
    // cout<<"hi\n";
    m=n;
    while(flag){
        // cout<<"n="<<n<<"\n";
        a = get_no_divisors(n);
        if(a==m){
            flag=0;
        }
        else{
            n+=1;
        }

    }

    cout<<n;


    return 0;
}