#include<bits/stdc++.h>
using namespace std;
int b,m;
long long int mod(int p){
    if(p > 1){
        long long int x = mod(p/2);
        if((p%2) == 1){
            return (x*x*b)%m;
        }
        else{
            return (x*x)%m;
        }
    }
    else if(p == 1){
        return b%m;
    }
    return 1;
}
int main(){
    int p;
    while(cin >> b >> p >> m){
        cout << mod(p) << endl;
    }
}