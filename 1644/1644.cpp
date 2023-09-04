#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,index;
    int *prime;
    prime = (int*)malloc(1300000*sizeof(int));
    vector<int> v;
    v.push_back(2);
    for(int i=3;i<1300000;i++){
        prime[i] = 1;
    }
    for(int i=3;i<1300000;i+=2){
        if(prime[i]){
            v.push_back(i);
            for(int j=3*i;j<1300000;j+=2*i){
                prime[j] = 0;
            }
        }
    }
    while(cin >> num && num){
        index = 0;
        while(v[index] < num){
            index++;
        }
        if(v[index] == num){
            cout << 0 << endl;
        }
        else{
            cout << v[index] - v[index-1] << endl;
        }
    }
}