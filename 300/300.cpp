#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
    int cases;
    string a,b;
    int d1,m1,y1,num,d2,y2;
    string m2;
    string name1[19]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
    string name2[20]={"imix", "ik", "akbal", "kan", "chicchan","cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
    cin >> cases;
    cout << cases << endl;
    for(int i=0;i<cases;i++){
        cin >> a >> b >> y1;
        d1 = stoi(a.substr(0,a.size()-1));
        for(int j=0;j<19;j++){
            if(b == name1[j]){
                m1 = j;
                break;
            }
        }
        
        num = d1 + m1 * 20 + y1 * 365;
        y2 = num / 260;
        
        m2 = name2[num % 20];
        d2 = num % 13 + 1;
        cout << d2 << " " << m2 << " " << y2 << endl;
    }
}