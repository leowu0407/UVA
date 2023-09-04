#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
using namespace std;
int main(){
    bool *arr;
    vector<int> v;
    int num;
    arr = (bool *)malloc(20000000 * sizeof(bool) );
    memset(arr,1,20000000*sizeof(arr[0]));
    arr[0]=arr[1]=0;
    for(int i=4;i<=20000000;i+=2){         //2的倍數都不是質數
        arr[i]=0;
    }
    for(int i=3;i<=20000000;i+=2){         
        if(arr[i]){       //質數
            if(arr[i+2]){
                v.push_back(i);
            }
            for(int j=3*i;j<20000000;j+=(2*i)){      ///質數的倍數
                arr[j]=0;
            }
        }
    }
    while(scanf("%d", &num) != EOF){
        printf("(%d, %d)\n", v[num-1], v[num-1]+2);
    }
}