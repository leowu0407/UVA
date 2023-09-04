#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,count,index;
    int prime[33000];
    vector<int> v;
    memset(prime,1,sizeof(prime));
    v.push_back(2);
    for(int i=4;i<33000;i+=2){
        prime[i] = 0;
    }
    for(int i=3;i<33000;i+=2){
        if(prime[i]){
            v.push_back(i);
            for(int j=3*i;j<33000;j+=2*i){
                prime[j] = 0;
            }
        }
    }
    while(cin >> num && num){
        count = 0;
        index = -1;
        while((num/2) >= v[++index]){
            if(prime[num-v[index]])
                count++;
        }
        cout << count << endl;
    }
}