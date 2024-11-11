/* practical 1B - 0/1 Knapsack using Dynamic Programming*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;



pair<int, vector<int>> knapsack_01(int M, int n, vector<vector<int>> data){
    vector<vector<int>> table;
    vector<int> row(M+1, 0);
    for(int i=0; i<=n; i++){
        table.push_back(row);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=M; j++){
            if (j < data[i-1][0]){
                table[i][j] = table[i-1][j];
            }else{
                table[i][j] = max(table[i-1][j], data[i-1][1] + table[i-1][j - data[i-1][0]]);
            }
        }
    }

    cout << "\nTable" << endl;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=M; j++){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    pair<int, vector<int>> ans;
    ans.first = table[n][M];

    vector<int> select;

    int k = M;
    for(int i=n; i>0; i--){
        if (table[i-1][k] != table[i][k]){
            select.push_back(i);
            k -= data[i-1][0];
        }
    }
    ans.second = select;
    return ans;
}



int main(){
    vector<vector<int>> list_dp;
    cout << "Enter Total Capacity of Sack: ";
    int M;
    cin >> M;
    cout << endl;
    cout << "Enter Number of Items: ";
    int n;
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++){
        int item, weight, profit;
        
        item = i+1;
        cout << "Enter Weight for Item " << item << " :";
        cin >> weight;
        cout << "Enter Profit for Item " << item << " :";
        cin >> profit;

        vector<int> temp_dp;
        
        temp_dp.push_back(weight);
        temp_dp.push_back(profit);
        list_dp.push_back(temp_dp);
        cout << endl;
    }
    cout << endl;
   
    cout << "DP 0/1 Approach" << endl;
    pair<int, vector<int>> ans = knapsack_01(M, n, list_dp);

    cout << "Maximum Profit Possible for given Knapsack is : " << ans.first << endl;
    cout << "Selected Items Numbers are : " << endl;
    for(int i=0; i<ans.second.size(); i++){
        cout << ans.second[i] << " ";
    }
    cout<<endl;
}
/*
Enter Total Capacity of Sack: 8

Enter Number of Items: 4

Enter Weight for Item 1 :2
Enter Profit for Item 1 :1

Enter Weight for Item 2 :3
Enter Profit for Item 2 :2

Enter Weight for Item 3 :4
Enter Profit for Item 3 :5

Enter Weight for Item 4 :5
Enter Profit for Item 4 :6


DP 0/1 Approach

Table
0 0 0 0 0 0 0 0 0
0 0 1 1 1 1 1 1 1
0 0 1 2 2 3 3 3 3 
0 0 1 2 5 5 6 7 7
0 0 1 2 5 6 6 7 8

Maximum Profit Possible for given Knapsack is : 8
Selected Items Numbers are :
4 2
*/