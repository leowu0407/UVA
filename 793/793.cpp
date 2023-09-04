#include<bits/stdc++.h>
using namespace std;
int main(){
    int cases,num,successful,unsuccessful,temp,x,y;
    string a;
    int b,c;
    cin >> cases;
    cin >> a;
    for(int i=0;i<cases;i++){
        num = stoi(a);
        if(i){
            cout << endl;
        }
        int arr[num+1];
        for(int j=1;j<=num;j++){       //初始組別為自己的編號
            arr[j] = j;
        }
        successful = 0;
        unsuccessful = 0;
        while(cin >> a && (a == "c" || a == "q")){
            cin >> b >> c;
            if(a == "c"){
                if(arr[b]>arr[c]){
                    x = arr[c];
                    y = arr[b];
                }
                else{
                    x = arr[b];
                    y = arr[c];
                }
                if(x != y){
                    for(int j = 1;j<=num;j++){         //把組別編號較大的那一組合併到另一組
                        if(arr[j] == y){
                            arr[j] = x;
                        }
                    }
                }
            }
            else if(a == "q"){
                if(arr[b] == arr[c]){
                    successful++;
                }
                else{
                    unsuccessful++;
                }
            }
        }
        cout << successful << "," << unsuccessful << endl; 
    }
}