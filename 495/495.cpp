#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    vector<int> v[5001];
    v[0].push_back(0);
    v[1].push_back(1);
    for(int i=2;i<=5000;i++){
        for(int j=0;j<v[i-2].size();j++){
            v[i].push_back(v[i-1][j] + v[i-2][j]);
        }
        // for(int j=v[i].size()-1;j>=0;j--){
        //     cout << v[i][j] << " ";
        // }
        // cout << endl;
        for(int j=v[i-2].size();j<v[i-1].size();j++){
            v[i].push_back(v[i-1][j]);
        }
        // for(int j=v[i].size()-1;j>=0;j--){
        //     cout << v[i][j] << " ";
        // }
        // cout << endl;
        for(int j=0;j<v[i].size()-1;j++){
            v[i][j+1] += (v[i][j] / 10);
            v[i][j] %= 10;
        }
        // for(int j=v[i].size()-1;j>=0;j--){
        //     cout << v[i][j] << " ";
        // }
        // cout << endl;
        if(v[i][v[i].size()-1] >= 10){
            v[i].push_back(v[i][v[i].size()-1] / 10);
            v[i][v[i].size()-2] %= 10;
        }
        // for(int j=v[i].size()-1;j>=0;j--){
        //     cout << v[i][j] << " ";
        // }
        // cout << endl;
    }
    while(cin >> num){
        cout << "The Fibonacci number for " << num << " is ";
        for(int i=v[num].size()-1;i>=0;i--){
            cout << v[num][i];
        }
        cout << endl;
    }
}