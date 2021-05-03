#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k; 
vector< vector <bool> >vis;
vector < vector < bool > > space;
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int Dfs(int r, int c){
    
    int ret = 1;
    vis[r][c] = true;
    for(int i=0;i<4;i++){
        int nr = r + dx[i];
        int nc = c + dy[i];
        if(0<=nr&&nr<m&&0<=nc&&nc<n){
            if(vis[nr][nc]==true)continue;
            if(space[nr][nc]==true){
                ret += Dfs(nr,nc);
            }
        }
    }
    return ret;
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    space.resize(m,vector<bool>(n,false));
    vis.resize(m,vector<bool>(n,false));
    for(int i=0;i<k;i++){
        int a, b; cin >> a >> b;
        space[a-1][b-1] = true;
    }
    int ret = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]==false&&space[i][j]==true){
                ret = max(ret,Dfs(i,j));
            }
        }
    }
    cout << ret;
}