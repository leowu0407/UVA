#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,index;
    int prime[1000];
    memset(prime,1,sizeof(prime));
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    for(int i=4;i<1000;i+=2){
        prime[i] = 0;
    }
    for(int i=3;i<1000;i+=2){
        if(prime[i]){
            v.push_back(i);
            for(int j=3*i;j<1000;j+=2*i){
                prime[j] = 0;
            }
        }
    }
    while(cin >> a >> b){
        vector<int> list;
        cout << a << " " << b << ":";
        index = 0;
        while(v[index] <= a && (index < v.size())){
            list.push_back(v[index]);
            index++;
        }
        if(list.size() <= (2*b-1)){
            for(int i=0;i<list.size();i++){
                cout << " " << list[i];
            }
            cout << endl << endl;
        }
        else{
            if(list.size()%2){
                for(int i=list.size()/2-b+1;i<=list.size()/2+b-1;i++){
                    cout << " " << list[i];
                }
                cout << endl << endl;
            }
            else{
                for(int i=list.size()/2-b;i<=list.size()/2+b-1;i++){
                    cout << " " << list[i];
                }
                cout << endl << endl;
            }
        }
    }
}