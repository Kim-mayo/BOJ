#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9
int n;
vector < vector < int > > sti;
vector < vector < int > > dp;
int solve(int r,int c){

    if(c==n)return 0;

    if(dp[r][c]!=INF) return dp[r][c];
    dp[r][c] = -INF;

    dp[r][c] = max(dp[r][c],solve(1-r,c+1)+sti[r][c]);
    dp[r][c] = max(dp[r][c],solve(r,c+1));
    dp[r][c] = max(dp[r][c],solve(1-r,c+1));

    return dp[r][c];

}
void input(){

    int t; cin >> t;
    for(int k=0;k<t;k++){
        
        cin >> n;
        sti.resize(2);
        dp.resize(2,vector<int>(n,INF));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                int a; cin >> a;
                sti[i].push_back(a);
            }
        }
        cout << max(solve(0,0), solve(1,0)) << "\n";
        sti.clear();
        dp.clear();
    }

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    input();

}