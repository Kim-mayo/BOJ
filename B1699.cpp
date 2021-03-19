#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9
int dp[100001];
void prepare(int n){

    dp[0] = 0;
    dp[1] =1; dp[2] =2; dp[3] =3;
    for(int i=4;i<=n;i++){
        for(int j=1;j<i;j++){
            if(j*j>i)break;
            dp[i] = min(dp[i],dp[i-(j*j)]+1);
        }
    }
    cout << dp[n];
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i=0;i<=n;i++)dp[i] = INF;
    prepare(n);
}