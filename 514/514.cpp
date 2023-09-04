#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,index;
    bool ans;
    
    while(cin >> num && num){
        int seq[num];
        while(cin >> seq[0] && seq[0]){
            vector<int> v;
            ans = true;
            for(int i=1;i<num;i++){
                cin >> seq[i];
            }
            index = 1;
            for(int i=0;i<num;i++){
                while(index < seq[i]){
                    v.push_back(index);
                    index++;
                }
                if(index == seq[i]){
                    index++;
                }
                else{
                    if(v[v.size()-1] == seq[i]){
                        v.pop_back();
                    }
                    else{
                        ans = false;
                        break;
                    }
                }
            }
            if(ans){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        cout << endl;
    }
}