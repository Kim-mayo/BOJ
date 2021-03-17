#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define mod %10007
int dp[10][1001];
void solve(){

    for(int i=0;i<10;i++)dp[i][0] = 1;
    for(int i=0;i<1001;i++)dp[0][i] = 1;

    for(int i=1;i<10;i++){
        for(int j=1;j<1001;j++){
            dp[i][j] = ((dp[i-1][j])mod+(dp[i][j-1])mod)mod;
        }
    }

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    solve();
    int ans=0;
    for(int i=0;i<10;i++){
        ans = ((ans)mod + (dp[i][n-1])mod)mod;
    }
   cout << (ans)mod;

}