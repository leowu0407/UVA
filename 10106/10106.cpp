#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    while(cin >> a >> b){
        vector<int> v1,v2;
        vector<int> ans(a.size()+b.size(),0);
        for(int i=a.size()-1;i>=0;i--){
            v1.push_back(a[i]-'0');
        }
        for(int i=b.size()-1;i>=0;i--){
            v2.push_back(b[i]-'0');
        }
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                ans[i+j] += (v1[i]*v2[j]);
                ans[i+j+1] += (ans[i+j]/10);
                ans[i+j] %= 10;
            }
        }
        int index=ans.size()-1;
        while((ans[index] == 0) && index){
            index--;
        }
        if(index == 0){
            cout << ans[0];
        }
        else{
            for(int i=index;i>=0;i--){
                cout << ans[i];
            }
        }
        cout << endl;
    }
}