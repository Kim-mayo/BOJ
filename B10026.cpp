#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n; 
vector <vector <char> >section;
vector <vector <int> > visited;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void solve2(int row, int col, int g){

    if(visited[row][col] != -1) return;
    visited[row][col] = g;
    char curr = section[row][col];
    for(int i=0;i<4;i++){
        int nr = row+dx[i];
        int nc = col+dy[i];
        if(0<=nr&&nr<n&&0<=nc&&nc<n){
            if(visited[nr][nc] != -1)continue;
            if(curr=='B'&&section[nr][nc]=='B')solve2(nr,nc,g);
            else if(curr!='B'){
                if(section[nr][nc]=='R'||section[nr][nc]=='G'){
                    solve2(nr,nc,g);
                }
            }
        }
    }

}
void solve(int row, int col, int g){

    if(visited[row][col] != -1) return;
    visited[row][col] = g;
    char curr = section[row][col];
    for(int i=0;i<4;i++){
        int nr = row+dx[i];
        int nc = col+dy[i];
        if(0<=nr&&nr<n&&0<=nc&&nc<n){
            if(visited[nr][nc] != -1)continue;
            if(section[nr][nc] == curr){
                solve(nr,nc,g);
            }
        }
    }

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    section.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char a; cin >> a;
            section[i].push_back(a);
        }
    }
    int group=0;
    visited.resize(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==-1){
                solve(i,j,group);
                group++;
            }
        }
    }
    cout << group << "\n";
    group = 0;
    visited.clear();
    visited.resize(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==-1){
                solve2(i,j,group);
                group++;
            }
        }
    }
    cout << group;
}