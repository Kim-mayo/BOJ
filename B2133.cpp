#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; 
vector < vector < int > > dp;
int solve(int me, int bit){
    if(me>n)return 0;
    if(me==n){
        if(bit==0)return 1;
        else return 0;
    }
    if(dp[me][bit]!=-1) return dp[me][bit];
    dp[me][bit] = 0;
    if(bit==0){
        dp[me][0] += solve(me+2,0);
        dp[me][0] += solve(me+1,4);
        dp[me][0] += solve(me+1,1);
    }
    else if(bit==1){
        dp[me][1] += solve(me+1,0);
        dp[me][1] += solve(me+1,6);
    }
    else if(bit==3){
        dp[me][3] += solve(me+1,4);
    }
    else if(bit==4){
        dp[me][4] += solve(me+1,0);
        dp[me][4] += solve(me+1,3);
    }
    else if(bit==6){
        dp[me][6] += solve(me+1,1);
    }

    return dp[me][bit];
}
int main(){

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    dp.resize(n+1,vector<int>(7,-1));
    cout << solve(0,0);

    
}