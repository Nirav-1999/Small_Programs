#include<bits/stdc++.h>

using namespace std;



void complement_arr(vector<int> &result,int end,int B){

    for (int i = 1; i <= end; i++)
    {
        result[i] == 1 ? result[i] = 0 : result[i] = 1;
        result[B-i+1] == 1 ? result[B-i+1] = 0 : result[B-i+1] = 1;
        
    }
    
}

void store_result(vector<int> &result,int first,int last,int x1,int x2 ){
    
    result[first] = x1;
    result[last] = x2;
}

void reverse_arr(vector<int> &result,int end,int B){
    int temp;
    for (int i = 1; i <= end; i++)
    {
        temp = result[i];
        result[i] = result[B-i+1];
        result[B-i+1] = temp;
    }
    
}

void find_ans(int B){
    vector<int> result(B+1); 
    int flag_only_sim = 0, flag_only_diff = 0,x1,x2,temp1,temp2,pos_sim,pos_diff,query = 0,flag = 0;
    
    for (int i = 1; i <= B/2; i++)
    {
        std::cout<<i<<endl;
        cin>>x1;
        // result[i] = x1;
        std::cout<<B-i+1<<endl;
        cin>>x2;
        // result[B-i+1] = x2;
        query++;
        if(query%11 == 0){
            flag = 1;
        }
        query++;
        if(query%11 == 0){
            flag = 1;
        }
        // cout<<"Flag = "<<flag<<"\n";
        if(x1 == x2 && flag_only_sim == 0){
            flag_only_sim = 1;
            pos_sim = i;
        }
        else if(x1!=x2 && flag_only_diff == 0){
            flag_only_diff = 1;
            pos_diff = i;
        }

        // cout<<"query_no :"<<query<<"\n";
        // cout<<"i = "<<i<<"\n";
        
        if(i==1){
            store_result(result,i,B-i+1,x1,x2);
            continue;
        }
        
        else if( flag == 1 ){
            if((flag_only_sim == 1 && flag_only_diff == 0) || (flag_only_sim == 0 &&  flag_only_diff== 1) ){
                std::cout<<i-1;
                cin>>temp1;
                query += 1;
                if(result[i-1] != temp1 ){
                    complement_arr(result,i-1,B);
                }
            }

            else{
                std::cout<<pos_sim;
                cin>>temp1;
                std::cout<<pos_diff;
                cin>>temp2;
                query += 2;
                if(temp1 == result[pos_sim] && temp2 != result[pos_diff]){
                    reverse_arr(result,i-1,B);
                    
                }
                else if(temp1 != result[pos_sim] && temp2 == result[pos_diff]){
                    reverse_arr(result,i-1,B);
                    complement_arr(result,i-1,B);
                }
                else if(temp1 != result[pos_sim] && temp2 != result[pos_diff]){
                    complement_arr(result,i-1,B);
                }
            }
            store_result(result,i,B-i+1,x1,x2);
            flag = 0;
        }
        else{
            result[i] = x1;
            result[B-i+1] = x2;
        }
        // for (int k = 1; k <= i ; k++)
        // {
        //     std::cout<<result[k]<<"start\n";
        // }
        // for (int k = 1; k <= i ; k++)
        // {
        //     std::cout<<result[B-k+1]<<"end\n";
        // }
        // cout<<val;
        // ans.push_back(val);
        // cout<<ans<<endl;
    
    }
    stringstream ans;
    std::copy(result.begin()+1, result.end(), ostream_iterator<int>(ans, ""));
    std::cout<<ans.str().c_str()<<endl;
    
}

int main(){
    int T,B;
    char res;
    cin >> T >> B;

    for (int i = 0; i < T; i++)
    {
        find_ans(B);
        cin>>res;
        if(res == 'N'){
            break;
        }
    }
    



    return 0;
}