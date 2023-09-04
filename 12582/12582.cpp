#include<bits/stdc++.h>
using namespace std;
int main(){
    int cases;
    bool repeat;
    string str;
    cin >> cases;
    for(int i=0;i<cases;i++){
        cin >> str;
        vector<char> v;
        int num[26]={0};
        v.push_back(str[0]);
        for(int j=1;j<str.size();j++){
            repeat = false;
            for(int k=0;k<v.size();k++){
                if(str[j] == v[k]){          //沒有子節點了
                    repeat = true;
                    v.erase(v.begin()+k);    
                    break;
                }
            }
            if(!repeat){       //沒有重複,代表是新的節點
                v.push_back(str[j]);
                num[v[v.size()-1]-'A'] += 1;  
                num[v[v.size()-2]-'A'] += 1;
            }
        }
        cout << "Case " << i+1 << endl;
        for(int j=0;j<26;j++){
            if(num[j]){
                cout << (char)('A'+j) << " = " << num[j] << endl;
            }
        }
    }
}