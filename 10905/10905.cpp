#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b){         //大的放前面
    return a+b > b+a;
}
int main(){
    int num;
    while(cin >> num && num){
        string str;
        vector<string> v;
        for(int i=0;i<num;i++){
            cin >> str;
            v.push_back(str);
        }
        sort(v.begin(),v.end(),cmp);      //大到小排序
        for(int i=0;i<num;i++){
            cout << v[i];
        }
        cout << endl;
    }
}