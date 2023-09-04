#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){                //按照index從小排到大
    return a.first < b.first;
}
int main(){
    string str;
    vector<pair<int,int>> v;
    int node[256];                        //記錄所有index
    int n,index,numOfNode = 0;
    bool complete = true;                 //紀錄是否為complete
    while(getline(cin,str)){             //一次讀一行
        for(int i=0;i<str.size();i++){   
            if(str[i] == '('){           //讀到左括號,代表後面有一個node
                if(str[i + 1] == ')'){   //若下一個為右括號,表示該case結束
                    break;
                }
                i++;                         //跳到下一個字元
                n = 0;                       //用來存取該node的數字
                while(isdigit(str[i])){      //將字元轉數字
                    n *= 10;
                    n += (str[i] - 48);
                    i++;
                }
                index = 1;   //用來紀錄該node的位置
                i++;       //跳過逗號
                while(str[i] != ')'){
                    if(str[i] == 'L'){    //L代表往左,所以乘2
                        index *= 2;
                    }
                    else{                 //往右則乘2再加1
                        index = index * 2 + 1;
                    }
                    i++;
                }
                v.push_back(make_pair(index,n));   //存到vector中
                node[numOfNode] = index;           //紀錄有用到的index
                numOfNode++;                       //node個數+1
            }
            else{
                continue;
            }
        }
        if((str[str.size() - 2] == '(') && (str[str.size() - 1] == ')')){        //代表該case輸入結束
            sort(v.begin(),v.end(),cmp);          //按照index從小排到大
            string a = "";                        //用來記錄答案
            for(int i=0;i<v.size();i++){
                int *ptr = find(node, node+numOfNode, v[i].first/2);      //計算該節點parent的index
                if((v[i].first != 1) && (ptr == (node+numOfNode))){    //看該節點的parent是否存在
                    complete = false;
                    break;
                }
                if((v[i].first == v[i+1].first) && (i != v.size()-1)){                        //看是否有重複的index
                    complete = false;
                    break;
                }
                a += (to_string(v[i].second) + " ");
            }
            if(!complete){          //錯誤的情況
                cout << "not complete" << endl;
            }
            else{        //正確的情況
                a.pop_back();     //由於最後會多一個空格,因此將最後一個字元移除
                cout << a << endl;
            }
            v.clear();           //清空vector
            complete = true;
            numOfNode = 0;
            memset(node,sizeof(node),0);        //初始化為0
        }
    }
}