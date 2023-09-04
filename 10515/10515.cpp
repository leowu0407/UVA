//只看個位數就好
#include<bits/stdc++.h>
using namespace std;
int main(){
    int digit[10][4]={0,0,0,0,1,1,1,1,2,4,8,6,3,9,7,1,4,6,4,6,5,5,5,5,6,6,6,6,7,9,3,1,8,4,2,6,9,1,9,1};           //找出規律(每4次方為1個循環)
    string m,n;
    int x,y;
    while(cin >> m >> n && (m != "0") && (n != "0")){
        if(n == "0"){          //任何數的0次方都是1
            cout << 1 << endl;
            continue;
        }
        if(m == "0"){         //0的n次方
            cout << 0 << endl;
            continue;
        }
        x = m[m.size()-1]-'0';  //m的最後1位
        if(n.size() == 1){
            y = n[0]-'0';
        }
        else{
            y = (n[n.size()-2]-'0')*10 + n[n.size()-1]-'0';          //只看最後兩位,因為百位數以上會被4整除
        }
        cout << digit[x][(y+3)%4] << endl;
    }
}