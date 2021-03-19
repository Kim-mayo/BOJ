#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF -1e9
int n,m;
vector < vector < int > >maze;
vector < vector < int > > dp;
queue < int > q;
void solve(){
    dp.resize(n,vector<int>(m,INF));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(i-1<0){
                dp[i][j] = maze[i][j] + dp[i][j-1];
                continue;
            }
            else if(j-1<0){
                dp[i][j] = maze[i][j] + dp[i-1][j];
                continue;
            }
            int candy = max(dp[i-1][j],dp[i][j-1]);
            candy = max(candy,dp[i-1][j-1]);
            
            dp[i][j] = candy+maze[i][j];
        }
    }
        
    

}
void input(){

    cin >> n >> m;
    maze.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a; cin >> a;
            maze[i].push_back(a);
        }
    }

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    cout << dp[n-1][m-1];
}