#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    int index=1;
    vector<int> v;
    while(getline(cin,a)){
        getline(cin,b);
        int lcs[a.size()+1][b.size()+1];
        for(int i=0;i<=a.size();i++){
            lcs[i][0] = 0;
        }
        for(int i=0;i<=b.size();i++){
            lcs[0][i] = 0;
        }
        for(int i=1;i<=a.size();i++){
            for(int j=1;j<=b.size();j++){
                if(a[i-1] == b[j-1]){
                    lcs[i][j] = lcs[i-1][j-1]+1;
                }
                else if(lcs[i-1][j] >= lcs[i][j-1]){
                    lcs[i][j] = lcs[i-1][j];
                }
                else{
                    lcs[i][j] = lcs[i][j-1];
                }
            }
        }
        cout << lcs[a.size()][b.size()] << endl;
    }
    
}