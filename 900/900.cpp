#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int f[51]={1,1};   //費式數列
    int num;
    for(int i=2;i<=50;i++){
        f[i] = f[i-1] + f[i-2];
    }
    while(cin >> num && num){
        cout << f[num] << endl;
    }   
}