#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
int n;
vector < vector < int > > arr;
vector < vector < ll > > dp;
ll solve(int r, int c){

    if(r==n-1&&c==n-1)return dp[r][c]= 1;
    if(dp[r][c]!=-1)return dp[r][c];
    dp[r][c] = 0;
    
    int down = r+arr[r][c];
    if(0<=down&&down<n){
        dp[r][c] += solve(r+arr[r][c],c);
    }
    int ri = c+arr[r][c];
    if(0<=ri&&ri<n){
    dp[r][c] += solve(r,c+arr[r][c]);
    }
    
    return dp[r][c];
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    arr.resize(n);
    dp.resize(n,vector<ll>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a; cin >> a;
            arr[i].push_back(a);
        }
    }
    cout << solve(0,0);


}