#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, m; 
int ans=-1;
vector<int>vol;
bool arr[101][1001];
void solve(int volume){

    arr[0][volume] = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            if(arr[i][j]==true){
                int nextP = j + vol[i];
                int nextM = j - vol[i];
                if (nextP <= m)
                {
                    arr[i + 1][nextP] = true;
                }
                if (nextM >= 0)
                {
                    arr[i + 1][nextM] = true;
                }
            }
        }
    }

}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> m;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        vol.push_back(a);
    }
    solve(s);
    bool nope = false;
    for(int i=0;i<=m;i++){
        if(arr[n][i]==true){
            ans = max(i,ans);
            nope = true;
        }
    }
    if(nope == false){
        cout << -1;
        return 0;
    }
    cout << ans;

}