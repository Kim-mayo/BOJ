#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define INF 1e9
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;

    int s = (int)to_string(n).size();
    int ans=0;
    int num=9;
    for(int i=1;i<s;i++){
        ans+=(num*i);
        num*=10;
    }
    num/=9;
    num = n-num+1;
    ans += num*s;

    cout << ans;

}