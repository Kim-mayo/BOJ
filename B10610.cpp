#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string n;
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int sum=0;
    int zero=0;
    for(int i=0;i<n.size();i++){
        sum += n[i]-'0';
        if(n[i]=='0')zero++;
    }
    if(zero>0&&sum%3==0){
        sort(n.rbegin(),n.rend());
        for(int i=0;i<n.size();i++){
            cout << n[i];
        }
    }
    else cout << -1;

}