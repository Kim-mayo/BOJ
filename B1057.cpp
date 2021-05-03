#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, jimin, hansoo; cin >> n >> jimin >> hansoo;
    
    jimin -= 1;
    hansoo -= 1;
    int ans = 0;
    while(jimin!=hansoo){
        jimin/=2;
        hansoo/=2;
        ans++;
    }
    cout << ans;
}