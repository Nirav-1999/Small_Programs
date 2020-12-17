/* Read input from STDIN. Print your output to STDOUT*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *a[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    for(int i = 0; i < T ; i++){
        int N,index_g = 0, index_o = 0,count = 0;
        cin>>N;
        vector<int> team_g(N);
        vector<int> other_team(N);
        for(int j = 0 ; j < N ; j++ ){
            cin>>team_g[j];
        }
        for(int j = 0 ; j < N ; j++ ){
            cin>>other_team[j];
        }

        sort(team_g.begin(), team_g.end(), greater<int>());
        sort(other_team.begin(), other_team.end(), greater<int>());

        for(int j = 0 ; j < N ; j++ ){
            if(team_g[index_g]>other_team[index_o]){
                count++;
                index_g++;
                index_o++;
            }
            else{
                index_o++;
            }
        }
        cout<<count<<"\n";

    }
}
