#include<bits/stdc++.h>

using namespace std;

int main(){

    int T;
    cin >> T;

    for (int c = 0; c < T; c++)
    {
        int C,N,max_x,max_y;
        cin >> N >> C;

        vector<int> colors(C,0);
        vector <vector <int>> rect(N, vector<int>(3));

        for (int i = 0; i < N; i++)
        {
            cin >> rect[i][0] >> rect[i][1] >> rect[i][2];
        }

        for (int i = N-1 ; i >= 0; i--)
        {
            if(i == N-1){
                colors[rect[i][2] - 1] += rect[i][0] * rect[i][1];
                max_x = rect[i][0];
                max_y = rect[i][1];

            }
            else{
                if((rect[i][0] - max_x > 0) && (rect[i][1] - max_y > 0)){
                    colors[rect[i][2] - 1] += (rect[i][0] - max_x) * rect[i][1] + (rect[i][1] - max_y) * rect[i][0] - ((rect[i][0] - max_x) * (rect[i][1] - max_y));
                    max_x = rect[i][0];
                    max_y = rect[i][1];
                }
                else if((rect[i][0] - max_x > 0))
                {
                    colors[rect[i][2] - 1] += (rect[i][0] - max_x) * rect[i][1];
                    max_x = rect[i][0];
                }
                else if((rect[i][1] - max_y > 0))
                {
                    colors[rect[i][2] - 1] += (rect[i][1] - max_y) * rect[i][0];
                    max_y = rect[i][1];
                }
                
                
            }

            // cout<<"Max_x = "<<max_x<<"\tMax_y = "<<max_y<<"\n";
            // cout<<"Color = "<<rect[i][2]<<"\tCurrent Color Vaue = "<<colors[rect[i][2] - 1]<<"\n";
        }
        for (int i = 0; i < C; i++)
        {
            cout<<colors[i]<<" ";
        }
        cout<<"\n";
        
        
        


    }
    



    return 0;
}