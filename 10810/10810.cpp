//merge sort分成兩堆,有交換的話看第一堆剩多少個數字,count就加多少(因為代表該數字要跟前面的n個數字交換)
#include<iostream>
#include<stdio.h>
using namespace std;
long long int count;
int temp[500000];
void mergesort(int arr[], int l,int r){
    if(r-l > 1){
        mergesort(arr,l,(l+r)/2);           //左邊
        mergesort(arr,(l+r)/2+1,r);         //右邊
    }
    if(l == r){
        return;
    }
    else{
        int x = l, y = (l+r)/2+1;        //代表左邊和右邊當前的位置
        for(int i=l;i<=r;i++){
            if(x == ((l+r)/2+1)){        //代表左邊排完了
                temp[i] = arr[y];
                y++;
            }
            else if(y == (r+1)){         //右邊排完
                temp[i] = arr[x];
                x++;
            }
            else if(arr[y] > arr[x]){    
                temp[i] = arr[x];
                x++;
            }
            else{                         
                temp[i] = arr[y];
                y++;
                count += ((l+r)/2-x+1);   //右邊的要放到前面,交換次數增加
            }
        }
    }
    for(int i=l;i<=r;i++){                //更新原本的array
        arr[i] = temp[i];
    }
    return;

}
int main(){
    int num;
    while(scanf("%d", &num) && num){
        count = 0;
        int arr[num];
        for(int i=0;i<num;i++){
            scanf("%d", &arr[i]);
        }
        mergesort(arr,0,num-1);
        cout << count << endl;
    }
}