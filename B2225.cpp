#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define mod %1000000000
#define ll long long
int n,k;
vector <vector <ll> >vec;

void solve(){
    
    for(int i=0;i<=n;i++)vec[i][1] = 1;
    for(int i=1;i<=k;i++)vec[0][i] = 1;
    for(int i=1;i<=n;i++){
        for(int j=2;j<=k;j++){
            vec[i][j] = ((vec[i-1][j])mod+(vec[i][j-1])mod)mod;
        }
    }
    return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    vec.resize(n+1,vector<ll>(k+1));
    solve();
    cout << vec[n][k];

}