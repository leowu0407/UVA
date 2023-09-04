#include<bits/stdc++.h>
using namespace std;
int main(){
    int cases;
    string str;
    map<string,int> m;
    cin >> cases;
    for(int i=0;i<cases;i++){
        cin >> str;
        m[str]++;
        getline(cin,str);
    }
    for(auto x:m){
        cout << x.first << " " << x.second << endl;
    }
}