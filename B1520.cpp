#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector < vector < int > > arr;
vector < vector < int > > dp;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int solve(int r,int c){
    if(r==n-1&&c==m-1)return dp[n-1][m-1]=1;
    if(dp[r][c]!=-1)return dp[r][c];
    dp[r][c]=0;
    for(int i=0;i<4;i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(0<=nr&&nr<n&&0<=nc&&nc<m){
            if(arr[r][c]>arr[nr][nc]){
                dp[r][c] += solve(nr,nc);
            }
        }
    }
    return dp[r][c];
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    arr.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a; cin >> a;
            arr[i].push_back(a);
        }
    }
    dp.resize(n,vector<int>(m,-1));
    solve(0,0);
    cout << dp[0][0];
}