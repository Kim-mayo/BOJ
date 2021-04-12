#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n; 
vector <vector <int> >maze;
vector <vector <bool> >vis;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ans;
#define inf 1e9

void solve(){

    deque <pair <int,pair <int,int> > > dq;
    dq.push_front(make_pair(0,make_pair(0,0)));

    while(!dq.empty()){

        int curr = dq.front().first;
        int r = dq.front().second.first;
        int c = dq.front().second.second;
        dq.pop_front();
        if(r==n-1&&c==n-1){
            ans = curr; return;
        }
        if(vis[r][c]==true)continue;
        vis[r][c] = true;
        for(int i=0;i<4;i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(0<=nr&&nr<n&&0<=nc&&nc<n){
                if(vis[nr][nc] == true) continue;
                if(maze[nr][nc]==0){
                    dq.push_front(make_pair(curr,make_pair(nr,nc)));
                }
                else dq.push_back(make_pair(curr+1,make_pair(nr,nc)));
            }
        }
    }

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    maze.resize(n);
    vis.resize(n,vector<bool>(n,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char a; cin >> a;
            int b;
            if(a=='1')b=0;
            else b=1;
            maze[i].push_back(b);
        }
    }
    solve();
    cout << ans;
}