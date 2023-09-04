#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> prime;
    int arr[32000];
    memset(arr,1,sizeof(arr));
    prime.push_back(2);
    for(int i=4;i<32000;i+=2){
        arr[i] = 0;
    }
    for(int i=3;i<32000;i+=2){
        if(arr[i]){
            prime.push_back(i);
            for(int j=3*i;j<32000;j+=2*i){
                arr[j] = 0;
            }
        }
    }
    int cases,a,b,ans_num,ans_divisors,num,count,index,divisors;
    cin >> cases;
    for(int i=0;i<cases;i++){
        cin >> a >> b;
        ans_num = 0;
        ans_divisors = 0;
        for(int j=a;j<=b;j++){
            num = j;
            divisors = 1;
            index = 0;
            while(num != 1 && (index < prime.size())){
                count = 1;
                while(!(num%prime[index])){
                    count++;
                    num /= prime[index];
                }
                divisors *= count;
                index++;
            }
            if(divisors > ans_divisors){
                ans_divisors = divisors;
                ans_num = j;
            }
        }
        cout << "Between " << a << " and " << b << ", " << ans_num << " has a maximum of " << ans_divisors << " divisors." << endl;
    }
}