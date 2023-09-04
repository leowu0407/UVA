#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,in,cost,sum,index,temp;
    while(cin >> num && num){
        cost = 0;
        vector<int> v;
        for(int i=0;i<num;i++){
            cin >> in;
            v.push_back(in);
        }
        sort(v.begin(),v.end(),greater<int>());         //大排到小
        while(v.size() > 1){
            sum = (v[v.size()-1] + v[v.size()-2]);      //拿最小的兩個相加
            v.pop_back();
            v.pop_back();
            index = v.size()-1;
            if(v[index] > sum){                        //比最小的還小
                v.push_back(sum);
            }
            else{
                if(v[0] < sum){                        //比最大的還大  vector無法插入第一個,所以要另外處理
                    v.insert(v.begin(),sum);
                    temp = v[0];
                    v.erase(v.begin());
                    v.insert(v.begin(),temp);
                }
                else{
                    while((v[index] < sum) && index > 0){          //在vector中找到第1個比他大的數
                        index--;
                    }
                    v.insert(v.begin()+index+1,sum);
                }
                
            }
            cost += sum;
            
        }
        cout << cost << endl;
       
    }
    
}