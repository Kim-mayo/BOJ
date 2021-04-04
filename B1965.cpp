#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int > sq;
vector <int > dp;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n; 
    dp.resize(n+1);
    sq.push_back(0);
    for(int i=0;i<n;i++){
        int a; cin >> a;
        sq.push_back(a);
    }
    
    for(int i=1;i<=n;i++){
        int big =-1;
        for(int j=1;j<i;j++){
            if(sq[i]>sq[j]&&dp[i]<dp[j]+1){//?
                dp[i] = dp[j]+1;
                big = max(dp[i],big);
            }
        }
        //cout << dp[i] << " ";
    }
    int ans=-1;
    for(int i=1;i<dp.size();i++){
        ans = max(ans,dp[i]);
    }
    cout << ans+1;
}