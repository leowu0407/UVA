#include<bits/stdc++.h>
using namespace std;
int main(){
    int cases,num,people,ans;
    cin >> cases;
    for(int i=0;i<cases;i++){
        cin >> num;
        int object[num][2];        //商品重量和金額
        ans = 0;
        for(int j=0;j<num;j++){
            cin >> object[j][0] >> object[j][1];
        }
        cin >> people;
        int maxWeight[people];
        for(int j=0;j<people;j++){     //最大重量
            cin >> maxWeight[j];
        }
        
        for(int j=0;j<people;j++){

            int dp[31]={0};
            for(int k=0;k<num;k++){
                for(int w=maxWeight[j];w>=0;w--){
                    if(w>=object[k][1]){
                    dp[w] = max(dp[w], dp[w-object[k][1]]+object[k][0]);       //看拿了該物品金額是否會變高
                    }
                }
            }

            ans += dp[maxWeight[j]];
        }
        
        cout << ans << endl;
    }
}
