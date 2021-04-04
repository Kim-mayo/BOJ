#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define mod %=1000000
vector < int > dp;
string s;
// int solve(int me){
//     if(me==0)return 1;
//     if(me==1){
//         if(s[s.size()-1]=='0')return 0;
//         else return 1;
//     }
//     if(dp[me]!=-1) return dp[me];
//     dp[me]=0;

//     int num = 0;
//     int idx = s.size()-me;
//     for(int i=idx;i<s.size();i++){
//         num = num*10+(s[i]-'0');
//         if(0<num&&num<=26){
//             dp[me]+=solve(me-(i-idx)-1);
//             (dp[me])mod;
//         }
//         else break;
//     }
    
//     return dp[me];
// }
int solve(int me){
    if(me==s.size())return 1;
    if(me==s.size()-1){
        if(s[me]=='0')return 0;
        else return 1;
    }

    if(dp[me] != -1) return dp[me];
    dp[me] = 0;

    int num = 0;
    for(int i=me;i<me+2;i++){
        num = num*10+(s[i]-'0');
        if(0<num&&num<=26){
            dp[me] += solve(i+1);
            (dp[me])mod;
        }
        else break;
    }
    return dp[me];
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    dp.resize(s.size()+1,-1);
    cout << solve(0);
}