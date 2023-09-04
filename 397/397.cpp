#include<bits/stdc++.h>
using namespace std;
int main(){
    string str,name;
    int x;
    bool sign,neg,print = false;
    while(getline(cin,str)){
        if(print){
            cout << endl;
        }
        print = true;
        vector<char> op;
        vector<int> num;
        sign = false;
        neg = false;
        for(int i=0;i<str.size();i++){
            if(str[i] == ' '){
                continue;
            }
            if(str[i] == '='){
                while(str[++i] == ' '){
                    continue;
                }
                name = str.substr(i,str.size()-i);
                break;
            }
            if(!sign){
                if(str[i] == '-'){
                    neg = true;
                }
                else if(str[i] == '+'){
                    continue;
                }
                else{
                    x = str[i]-'0';
                    while(isdigit(str[++i])){
                        x *= 10;
                        x += (str[i]-'0');
                    }
                    i--;
                    if(!neg){
                        num.push_back(x);
                    }
                    else{
                        num.push_back(x*-1);
                    }
                    sign = true;
                    neg = false;
                }
            }
            else{
                op.push_back(str[i]);
                sign = false;
            }
        }
        int index = 0;
        cout << num[0];
        for(int j=0;j<op.size();j++){
            cout << " " << op[j] << " " << num[j+1];
        }
        cout << " = " << name << endl;
        while(op.size() > 1){
            if(index == op.size()){
                if(op[0] == '+'){
                    num[0] = num[0]+num[1];
                    num.erase(num.begin()+1);
                }
                else{
                    num[0] = num[0]-num[1];
                    num.erase(num.begin()+1);
                }
                op[0] = op[1];
                op.erase(op.begin()+1);
                cout << num[0];
                for(int j=0;j<op.size();j++){
                    cout << " " << op[j] << " " << num[j+1];
                }
                cout << " = " << name << endl;
                index = -1;
            }
            if(op[index] == '*'){
                num[index] = num[index]*num[index+1];
                num.erase(num.begin()+index+1);
                if(index != (op.size()-1)){
                    op[index] = op[index+1];
                    op.erase(op.begin()+index+1);
                }
                else{
                    op.erase(op.begin()+index);
                }
                cout << num[0];
                for(int j=0;j<op.size();j++){
                    cout << " " << op[j] << " " << num[j+1];
                }
                cout << " = " << name << endl;
                index = -1;
            }
            else if(op[index] == '/'){
                num[index] = num[index]/num[index+1];
                num.erase(num.begin()+index+1);
                if(index != (op.size()-1)){
                    op[index] = op[index+1];
                    op.erase(op.begin()+index+1);
                }
                else{
                    op.erase(op.begin()+index);
                }
                cout << num[0];
                for(int j=0;j<op.size();j++){
                    cout << " " << op[j] << " " << num[j+1];
                }
                cout << " = " << name << endl;
                index = -1;
            }
            index++;
        }
        if(op[0] == '+'){
            cout << num[0]+num[1];
        }
        else if(op[0] == '-'){
            cout << num[0]-num[1];
        }
        else if(op[0] == '*'){
            cout << num[0]*num[1];
        }
        else{
            cout << num[0] / num[1];
        }
        cout << " = " << name << endl;
    }
}