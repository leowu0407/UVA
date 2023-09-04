#include<bits/stdc++.h>
using namespace std;
int main(){
    int cases;
    string str;
    cin >> cases;
    for(int i=0;i<cases;i++){
        cin >> str;
        sort(str.begin(),str.end());
        cout << str << endl;
        while(next_permutation(str.begin(),str.end())){
            cout << str << endl;
        }
        cout << endl;
    }
}