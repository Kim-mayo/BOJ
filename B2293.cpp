#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1e9
int n,k; 
vector < int > coin;
vector < vector < int > >dp;
void solve(){

    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){

            if(j<coin[i-1]){
                dp[i%2][j] = dp[(i-1)%2][j]; 
            }
            else{ 
                dp[i%2][j] = dp[(i-1)%2][j] + dp[i%2][j-coin[i-1]];
            }
         
            
        }
    }

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    dp.resize(2,vector<int>(k+1,0));
    for(int i=0;i<n;i++){
        int a; cin >> a;
        coin.push_back(a);
    }
    solve();
    cout << dp[n%2][k];
}