#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int i=0;i<t;i++){
        string a; cin >> a;
        cout << (a[0]-'0')+(a[2]-'0') << "\n";
    }
}