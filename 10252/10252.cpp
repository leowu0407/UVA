#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    while(getline(cin,a)){
        getline(cin,b);
        int arr[26][2];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<a.size();i++){
            arr[a[i]-'a'][0] += 1;
        }
        for(int i=0;i<b.size();i++){
            arr[b[i]-'a'][1] += 1;
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<min(arr[i][0],arr[i][1]);j++){
                cout << char(i+'a');
            }
        }
        cout << endl;
    }
}