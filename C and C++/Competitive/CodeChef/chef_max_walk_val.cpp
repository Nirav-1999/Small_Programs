#include<bits/stdc++.h>

using namespace std;

int flag = 0;

vector<vector <int>> create_adjacency_matrix(vector<int > arr,int n){
    vector<vector <int >> adj_matrix(n, vector<int>(n,0));
    for (int i = 0; i < n-1; i++)
    {
        adj_matrix[arr[i]][i+1] = 1;
        adj_matrix[i+1][arr[i]] = 1;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout<<adj_matrix[i][j]<<"\t";
    //     }
    //     cout<<"\n";
        
    // }
    return adj_matrix;
    
}

vector<int> find_path(vector <int > path,int s_node,int d_node,int w, vector<vector <int>> adj_matrix,int n,int i, vector<int> visited,int weight,vector<int> weights_arr){
    if(visited[i] == 0){
        if(adj_matrix[s_node][i]==1){
            visited[i]=1; 
            if(weight + weights_arr[i]<=w){
                weight += weights_arr[i];
                path.push_back(weights_arr[i]);
                cout<<i<<"\t";
                if(d_node == i){
                    flag = 1;
                    return path;
                }
                path = find_path(path,i,d_node,w,adj_matrix,n,0,visited,weight,weights_arr);

            }
            else{
                return path;
            }
        }
        else{
            path = find_path(path,s_node,d_node,w,adj_matrix,n,i+1,visited,weight,weights_arr);
        }
    }
    else if(flag==0 && i<n){
        path = find_path(path,s_node,d_node,w,adj_matrix,n,i+1,visited,weight,weights_arr);
    }
    return path;
    
    
}

int main(){

    int n,no_special_nodes,no_queries,temp;

    cin>>n>>no_special_nodes>>no_queries;
    // cout<<n<<special_nodes<<no_queries;
    vector<int > input_arr(n), weights_arr(n), special_nodes(no_special_nodes);
    vector<vector <int>> queries(no_queries, vector<int>(3)),adj_matrix;
    for (int i = 0; i <n-1 ; i++)
    {
        cin>>temp;
        input_arr[i] = temp-1;
        // cout<<input_arr[i]<<"\t";
        // cout<<"\t"<<i<<"\n";
    }
    for (int i = 0; i <n ; i++)
    {
        cin>>temp;
        weights_arr[i] = temp;
        
    }
    for (int i = 0; i <no_special_nodes ; i++)
    {
        cin>>temp;
        special_nodes[i] = temp-1;
        
    }
    for (int i = 0; i <no_queries ; i++)
    {
        cin>>temp;
        queries[i][0] = temp-1;
        cin>>temp;
        queries[i][1] = temp-1;
        cin>>queries[i][2];
        
    }
    // for (int i = 0; i <n-1 ; i++)
    // {
    //     cout<<input_arr[i];
    // }
    adj_matrix = create_adjacency_matrix(input_arr,n);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout<<adj_matrix[i][j]<<"\t";
    //     }
    //     cout<<"\n";
        
    // }

    for (int i = 0; i < no_queries; i++)
    {
        for (int j = 0; j < no_special_nodes; j++)
        {
            vector<int > path1, path2,visited(n,0);
            path1.push_back(weights_arr[queries[i][0]]);
            path2.push_back(weights_arr[queries[i][1]]);
            cout<<queries[i][0]<<"\t";
            if(queries[i][0] != special_nodes[j]){
                path1 = find_path(path1,queries[i][0],special_nodes[j],queries[i][2],adj_matrix,n,0,visited,weights_arr[queries[i][0]],weights_arr);
            }
            cout<<"\n=======PATH1========\n";
            for (int i = 0; i <path1.size() ; i++)
            {
                cout<<path1[i]<<"\t";
            }
            cout<<"\n******************\n";
            flag = 0;
            cout<<queries[i][1]<<"\t";
            if(queries[i][1] != special_nodes[j]){
                path2 = find_path(path2,queries[i][1],special_nodes[j],queries[i][2],adj_matrix,n,0,visited,weights_arr[queries[i][1]],weights_arr);
            }
            cout<<"\n*******PATH2********\n";

            for (int i = 0; i <path2.size() ; i++)
            {
                cout<<path2[i]<<"\t";
            }
            cout<<"\n==========END=============\n";
            flag = 0;

        }
        
        
    }
    

    
    

    return 0;
}