#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector <int> dp;
int solve(int num){
  
    if(num==0)return dp[num]=0;      
    if(dp[num]!=1e9) return dp[num];
    for(int i=1;i<=sqrt(num);i++){
        if(i*i<=num){
            dp[num] = min(dp[num],1 + solve(num-(i*i)));
        }
    }
    return dp[num];

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    dp.resize(n+1,1e9);
    solve(n);
    cout << dp[n];

}