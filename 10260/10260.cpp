#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    int num,prev = 0;
    while(cin >> str){
        prev = 0;
        for(int i=0;i<str.size();i++){
            switch(str[i]){
                case 'B': case 'F': case 'P': case 'V':
                    num = 1;
                    break;
                case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z':
                    num = 2;
                    break;
                case 'D': case 'T':
                    num = 3;
                    break;
                case 'L':
                    num = 4;
                    break;
                case 'M': case 'N':
                    num = 5;
                    break;
                case 'R':
                    num = 6;
                    break;
                default:
                    num = 0;
                    break;
            }
            if(num && (prev != num)){
                cout << num;
            }
            prev = num;
        }
        cout << endl;
    }
}