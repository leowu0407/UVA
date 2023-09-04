#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    int x,y,end_x,end_y,step,find,s,tempx,tempy;
    int move[8][2] = {2,1,2,-1,1,2,1,-2,-1,2,-1,-2,-2,1,-2,-1};        //8種方向可以走
    while(getline(cin,str)){                               //每次讀取1個case
        vector<int> vx,vy;                                 
        vx.push_back(str[0] - 'a');                        //初始位置  轉換成0~7的形式
        vy.push_back(str[1] - '1');
        end_x = str[3] - 'a';                              //終點
        end_y = str[4] - '1';
        step = -1;
        find = false;                                     //是否走到終點
        while(!find){
            s = vx.size();                                //現在的size
            for(int i=0;i<s;i++){                         //目前vector中的每種情況再多走1步      
                if((vx[0] != end_x) || (vy[0] != end_y)){    //還沒走到終點
                    for(int j=0;j<8;j++){                    //8種方向都嘗試
                        tempx = vx[0] + move[j][0];          //新的x座標
                        tempy = vy[0] + move[j][1];          //新的座標
                        if((tempx >= 0) && (tempx < 8) && (tempy >= 0) && (tempy < 8)){     //確認是否超出邊界
                            vx.push_back(tempx);            //將新的位置存到vector
                            vy.push_back(tempy);
                        }
                    }
                    vx.erase(vx.begin());                   //將該輪的起點刪除
                    vy.erase(vy.begin());
                }
                else{
                    find = true;
                    break;
                }
            }
            step++;
        }
        cout << "To get from " << str[0] << str[1] << " to " << str[3] << str[4] << " takes " << step << " knight moves." << endl;
    }
}