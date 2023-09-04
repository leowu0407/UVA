#include<bits/stdc++.h>
using namespace std;
int main(){
    int cases,num,index;
    cin >> cases;
    for(int i=0;i<cases;i++){
        cin >> num;
        if(num < 10){
            cout << num << endl;
            continue;
        }
        int arr[10]={0};
        
        for(int j=9;j>=2;j--){
            while(!(num%j)){
                arr[j]++;
                num /= j;
            }
        }
        if(num != 1){
            cout << -1 << endl;
        }
        else{
            for(int j=2;j<=9;j++){
                for(int k=0;k<arr[j];k++){
                    cout << j;
                }
            }
            cout << endl;
        }
    }
    
}