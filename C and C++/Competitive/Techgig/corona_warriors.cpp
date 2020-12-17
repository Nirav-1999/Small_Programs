#include<bits/stdc++.h>

using namespace std;

int min(vector<int> final_sum, vector<int> visited, int minIndex,int D,vector<vector <int>> doctor_efforts,int count)
{
    int min = minIndex;

    for (int i = 0; i < D; i++)
    {
        if(visited[i] == -1){
            if(final_sum[i] < final_sum[min]){
                min = i;
            }
            // else if(final_sum[i] == final_sum[min]){
            //     min = doctor_efforts[i][count] < doctor_efforts[min][count] ? i : min;
            // }

        }
        
    }

  
    

    return min;
}

int main(){
    int P,D,j,minIndex;
    
    cin>>P>>D;

    vector<vector <int>> doctor_efforts(D, vector<int>(P));
    vector<vector <int>> results(D, vector<int>(P));
    vector<int> final_sum(D);
    vector<int> visited(D,-1);
    vector<int> result(D,0);


    for (int i = 0; i < D; i++)
    {
        for (j = 0; j < P; j++)
        {
            cin >> doctor_efforts[i][j];
        }
        final_sum[i] = accumulate(doctor_efforts[i].begin(), doctor_efforts[i].end(), 0);
    }
    
    for (int i = 0; i < D; i++)
    {

        for (int i = 0; i < D; i++)
        {
            final_sum[i] = accumulate(doctor_efforts[i].begin(), doctor_efforts[i].end(), 0);
        }
        j = 0;
        minIndex = i;
        while (j < P)
        {
            if(j == 0){
                results[i][j] = doctor_efforts[i][j];
                result[i] += doctor_efforts[i][j];
            }
            else
            {
                int minEle = 0;
                for (int p = 0; p < D; p++)
                {
                    if(doctor_efforts[p][j] < doctor_efforts[minEle][j]){
                        minEle = p;
                    }
                }
                if(doctor_efforts[minEle][j] == doctor_efforts[minIndex][j]){
                    minEle = minIndex;
                }
                cout<<"minELE = "<<minEle<<"\n"<<"minIndex = "<<minIndex<<"\n";
                if(minEle != minIndex){
                    int newMin = min(final_sum,visited,minIndex,D,doctor_efforts,j);
                    if(newMin != minIndex){
                        visited[minIndex] = 0;
                        minIndex = newMin;
                    }   
                }
                else
                {
                    minIndex = minEle;
                }
                
                
                results[i][j] = doctor_efforts[minIndex][j];
                result[i] += doctor_efforts[minIndex][j];
            }

            cout<<"Min = "<<minIndex<<"\n";

            cout<<"Before Refreshing\n";
            for (int i = 0; i < D; i++)
            {
                for (int j = 0; j < P; j++)
                {
                    cout<<results[i][j]<<"\t";
                }
                cout<<"\n";
                
            }
    
            for (int k = 0; k < D; k++)
            {
                final_sum[k] = final_sum[k] - doctor_efforts[k][j];
            }
            cout<<"Refreshing\n";
            for (int k = 0; k < D; k++)
            {
                cout<<final_sum[k]<<"\t";
            }
            cout<<"\n";
            j++;
            
        }
        
        

    }


    // for (int i = 0; i < D; i++)
    // {
    //     for (int j = 0; j < P; j++)
    //     {
    //         cout<<results[i][j]<<"\t";
    //     }
    //     cout<<"\n";
        
    // }

    cout<<*min_element(result.begin(),result.end())<<"\n";
    

    




    return 0;
}