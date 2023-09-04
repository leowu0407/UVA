#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,index,start,sum,ans;
    int prime[10000];
    vector<int> v;
    memset(prime,1,sizeof(prime));
    v.push_back(2);
    for(int i=4;i<10000;i+=2){
        prime[i] = 0;
    }
    for(int i=3;i<10000;i+=2){
        if(prime[i]){
            v.push_back(i);
            for(int j=3*i;j<10000;j+=2*i){
                prime[j] = 0;
            }
        }
    }
    while(cin >> num && num){
        ans = 0;
        index = 0;
        while(v[index] < num){
            start = index;
            sum = 0;
            while(sum < num){
                sum += v[start];
                start++;
            }
            if(sum == num){
                ans++;
            }
            index++;
        }
        if(v[index] == num){
            ans++;
        }
        cout << ans << endl;
    }
}