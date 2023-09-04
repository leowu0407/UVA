#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,temp;
    while(cin >> a >> b >> c){
        if(a > b){
            temp = a;
            a = b;
            b = temp;
        }
        int ans = c/a;
        if(!(c%a)){                //整除,直接輸出答案
            cout << ans << endl;
            continue;
        }
        else{
            int t1 = c%a;          //剩餘時間
            for (int i=ans-1;i>=0;i--) {     //一次少一個漢堡
                if(t1 == 0){
                    break;
                }
                int t2 = c-i*a;            //多出來的時間
                int num = t2 / b;          //看多出來的時間能吃幾個另一種漢堡
                t2 -= num * b;             //剩下的時間
                if (t2 < t1) {             //剩餘時間要最少
                    t1 = t2;
                    ans = i + num;
                }
            }
            cout << ans;
            if(t1 > 0){
                cout << " " << t1;
            }
            printf("\n");
        }
    }
}