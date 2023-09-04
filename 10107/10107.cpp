#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,index;
    vector<int> v;
    while(cin >> num){
        if(!v.size())
            v.push_back(num);
        else{
            index = 0;
            while(v[index] < num && (index < v.size())){
                index++;
            }
            if(index == v.size()){
                v.push_back(num);
            }
            else if(index == 0){
                v.insert(v.begin()+1,num);
                v[1] = v[0];
                v[0] = num;
            }
            else{
                v.insert(v.begin()+index,num);
            }
        }
        if(v.size()%2){
            cout << v[v.size()/2] << endl;
        }
        else{
            cout << (v[v.size()/2-1]+v[v.size()/2])/2 << endl;
        }
    }
}