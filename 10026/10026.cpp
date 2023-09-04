#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,float> a, pair<int,float> b){                  //賠償金高的要優先做
    return a.second > b.second;
}
int main(){
    int cases,job;
    float a,b;
    cin >> cases;
    for(int i=0;i<cases;i++){
        if(i){                            //每個case間空一行
            cout << endl;
        }
        vector<pair<int,float>> v;       
        cin >> job;
        for(int j=0;j<job;j++){
            cin >> a >> b;
            v.push_back(make_pair(j+1,b/a));
        }
        sort(v.begin(),v.end(),cmp);     //排序
        cout << v[0].first;
        for(int j=1;j<job;j++){
            cout << " " << v[j].first;
        }
        cout << endl;
    }
}