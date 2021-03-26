#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; 
vector <int> num;
int op[4];
int big=-1e9;
int small=1e9;
void backt(int np, int value){

    if(np==n-1){
        small = min(small,value);
        big = max(big,value);
        return;
    }
    for(int i=0;i<4;i++){
        if(op[i]==0)continue;
        op[i]--;
        if(i==0){
            backt(np+1,value+num[np+1]);
        }
        else if(i==1){
            backt(np+1,value-num[np+1]);
        }
        else if(i==2){
            backt(np+1,value*num[np+1]);
        }
        else{
            if(value<0)backt(np+1,-((-value)/num[np+1]));
            else backt(np+1,value/num[np+1]);
        }
        op[i]++;
    }
    return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        num.push_back(a);
    }
    for(int i=0;i<4;i++){
        int a; cin >> a;
        op[i] = a;
    }
    backt(0,num[0]);

    cout << big << "\n" << small;
}