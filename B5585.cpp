#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int money; cin >> money;
    money = 1000-money;
    int coin[6] = {500,100,50,10,5,1};
    int don = 0;
    int i=0;
    while(money!=0){
        if(money-coin[i]<0){
            i++;
        }
        else {
            money -= coin[i];
            don++;
        }
    }
    cout << don;
}