#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <vector <int> > arr;//구간합 이차원배열!!!!!!!!!!!!어케해!!!!!!!
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    arr.resize(n+1,vector<int>(n+1,0));
    int sum =0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a; cin >> a;
            arr[i][j] = arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1] +a;
        }
    }
    
    for(int i=0;i<m;i++){
        int ans=0;
        int a,b,c,d; cin >> a >> b >> c >> d;
        ans = arr[c][d] - arr[a-1][d] - arr[c][b-1] + arr[a-1][b-1];
        cout << ans << "\n";
    }
}