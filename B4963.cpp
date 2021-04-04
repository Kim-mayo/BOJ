#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int w,h; 
vector < vector <int> > MAP;
vector < vector <bool> > visited;
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,1,-1};
void Dfs(int r, int c){

    if(visited[r][c]==true)return;
    visited[r][c] = true;

    for(int i=0;i<8;i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(0<=nr&&nr<h&&0<=nc&&nc<w){
           if(visited[nr][nc]==true)continue;
           if(MAP[nr][nc] == 1) Dfs(nr,nc);
        }
    }

    return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){

        cin >> w >> h;
        if(w==0 && h==0) break;
        MAP.resize(h);
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                int a; cin >> a;
                MAP[i].push_back(a);
            }
        }
        visited.resize(h,vector<bool>(w,false));
        int cnt =0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(MAP[i][j]==1&&visited[i][j]==false){
                    Dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
        MAP.clear();
        visited.clear();
    }

}