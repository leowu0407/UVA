#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,count;
    bool win;
    while(cin >> num && num){
        count = 1;
        win = true;
        while(count <= num){           
            count *= 2;
            if((count-1) == num){         //2^n-1  -> Bob贏  其他都是Alice贏
                win = false;
            }    
        }
        if(win){
            cout << "Alice" << endl;
        }
        else{
            cout << "Bob" << endl;
        }
    }
}