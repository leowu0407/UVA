#include<bits/stdc++.h>
using namespace std;
int main(){
    int cases;
    cin >> cases;
    double point[4][2];
    double x1,x2,y1,y2,c1,c2,x,y;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    for(int i=0;i<cases;i++){
        for(int j=0;j<4;j++){
            cin >> point[j][0] >> point[j][1];
        }
        if(point[1][0] == point[0][0]){
            x1 = 1;
            y1 = 0;
            c1 = point[0][0];
        }
        else if(point[1][1] == point[0][1]){
            x1 = 0;
            y1 = 1;
            c1 = point[0][1];
        }
        else{
            x1 = (point[1][1]-point[0][1])*-1;
            y1 = (point[1][0]-point[0][0]);
            c1 = x1*point[0][0] + y1*point[0][1];
        }
        if(point[3][0] == point[2][0]){
            x2 = 1;
            y2 = 0;
            c2 = point[2][0];
        }
        else if(point[3][1] == point[2][1]){
            x2 = 0;
            y2 = 1;
            c2 = point[2][1];
        }
        else{
            x2 = (point[3][1]-point[2][1])*-1;
            y2 = (point[3][0]-point[2][0]);
            c2 = x2*point[2][0] + y2*point[2][1];
        }
        
        if((x1/y1) == (x2/y2)){
            if((x2*c1/x1) == c2){
                cout << "LINE" << endl;
            }
            else{
                cout << "NONE" << endl;
            }
        }
        else{
            if(!x1){
                y = c1;
                x = (c2-y*y2)/x2;
            }
            else if(!x2){
                y = c2;
                x = (c1-y*y1)/x1;
            }
            else if(!y1){
                x = c1;
                y = (c2-x*x2)/y2;
            }
            else if(!y2){
                x = c2;
                y = (c1-x*x1)/y1;
            }
            else{
                y2 *= (x1/x2);
                c2 *= (x1/x2);
                x2 *= (x1/x2);
                y = (c2-c1)/(y2-y1);
                x = (c1-y*y1)/x1;
            }
            cout << "POINT " << fixed << setprecision(2) << x << " " << fixed << setprecision(2) << y << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;
}