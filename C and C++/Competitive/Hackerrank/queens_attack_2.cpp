#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool matters(int i,int j,int a,int b){
    if(i==a or j==b){
        return true;
    }
    else if(abs(i-a) == abs(j-b)){
        return true;
    }
    else{
    return false;
    }
}

int checkdir(int i,int j,int a,int b){
    if(i-a>0){              //Queen is above the obstacle
        if(j-b == 0){       //Obstacle is exactly below the queen     
            return 5;
        }
        else if(j-b>0){      //Obstacle is on the bottom left diagonal
            return 6;      
        }
        else{               //Obstacle is on the bottom right diagonal
            return 4;       
        }
    }
    else if(i-a<0){         //Queen is below the obstacle
        if(j-b == 0){       //Obstacle is exactly above the queen   
            return 1;
        }
        else if(j-b>0){     //Obstacle is on the upper left diagonal
            return 8;
        }
        else{               //Obstacle is on the upper right diagonal
            return 2;       
        }
    }
    else{
        if(j-b>0){          //Obstacle is on the left of the queen
            return 7;
        }
        else{               //Obstacle is on the right of the queen
            return 3;
        }
    }
}
// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int> > obstacles) {
    // int a[2];
    int up_down = n-r_q;
    int left_right = n-c_q;
    int dg = min( n-r_q,n-c_q);
    int count = 0;
    int dir[] = {n-r_q,min( n-r_q,n-c_q),n-c_q,min(r_q-1,n - c_q),r_q-1,min(r_q-1,c_q-1),c_q-1,min(n-r_q,c_q-1)};
    // for (int i = 0; i < 8; i++)
    // {
    //     cout<<dir[i]<<"\n";

    // }
    int direction,compare,row,col;
    for (int i = 0; i < k; i++)
    {   row = obstacles[i][0];
        col = obstacles[i][1];
        if(matters(r_q,c_q,row,col)){
            direction = checkdir(r_q,c_q,row,col);
            switch (direction)
            {
            case 1:
                compare = row - r_q-1;
                break;

            case 2:
                compare = row - r_q-1;
                break;

            case 3:
                compare = col - c_q-1;
                break;

            case 4:
                compare = r_q - row-1;
                break;

            case 5:
                compare = r_q - row-1;
                break;

            case 6:
                compare = r_q - row-1;
                break;

            case 7:
                compare = c_q - col-1;
                break;
            case 8:
                compare = row - r_q-1;
                break;

            }  
            // cout<<direction-1<<"\t$$\t"<<compare<<"\t$$\t"<<dir[direction-1]<<"\n";
            dir[direction-1] = min(dir[direction-1],compare);         
        }
    }
    for (int j = 0; j < 8; j++)
    {
        count+=dir[j];
    }
    // cout<<"=======================================\n";
    // for (int i = 0; i < 8; i++)
    // {
    //     cout<<dir[i]<<"\n";

    // }
    // cout<<"=======================================\n";
    // cout<<count;
    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int> > obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
