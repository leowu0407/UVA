#include<bits/stdc++.h>
using namespace std;
int main(){
    long int num;
    while(cin >> num && num){
        if(sqrt(num) == (int)sqrt(num)){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }

}