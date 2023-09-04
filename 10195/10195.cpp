#include<bits/stdc++.h>
using namespace std;
int main(){
    double a,b,c,radius,area,s;
    while(cin >> a >> b >> c){
        if(!a || !b || !c){   //有一邊長為0
            cout << "The radius of the round table is: 0.000" << endl;
            continue;
        }
        //海龍公式 area = sqrt(s*(s-a)*(s-b)(s-c))
        s = (a+b+c)/2;    //三邊和的一半
        area = sqrt(s*(s-a)*(s-b)*(s-c));  //海龍公式求面積
        //area = a*r/2+b*r/2+c*r/2 = (a+b+c)*r/2
        //r = area*2/(a+b+c)
        cout << "The radius of the round table is: " << fixed << setprecision(3) << area*2/(a+b+c) << endl;  //到小數後3位
    }
}