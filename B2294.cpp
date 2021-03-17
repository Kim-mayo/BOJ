#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9
int n, k; 
vector < int > coin;
vector < vector < int > > dp;
void solve(){
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            
            if(j-coin[i-1]<0){
                dp[i][j] = dp[i-1][j]; continue;
            }
            dp[i][j] = min(dp[i-1][j],dp[i][j-coin[i-1]]+1);

        }
    }
    
}
void input(){

    cin >> n >> k;
    dp.resize(n+1,vector<int>(k+1,INF));
    for(int i=0;i<n;i++){

        int a; cin >> a;
        coin.push_back(a);

    }

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solve();
    if(dp[n][k]==INF)dp[n][k] = -1;
    cout << dp[n][k];
   
}