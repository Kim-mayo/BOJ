#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; 
vector <vector <int> > area;
vector <vector <bool> > visited;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void Dfs(int r,int c,int limit){
    if(visited[r][c]==true)return;
    visited[r][c] = true;

    for(int i=0;i<4;i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(0<=nr&&nr<n&&0<=nc&&nc<n){
            if(visited[nr][nc]==true)continue;
            if(area[nr][nc]>limit)Dfs(nr,nc,limit);
           // else{visited[nr][nc]=true;}
        }
    }
    return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    area.resize(n);
    int low = 101;
    int high =-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a; cin >> a;
            area[i].push_back(a);
            high = max(high,a);
            low = min(low,a);
        }
    }
    
    int many =-1;
    for(int k=low-1;k<high;k++){
        visited.resize(n,vector<bool>(n,false));
        int island = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==false&&area[i][j]>k){
                    Dfs(i,j,k);
                    island++;
                }
            }
        }
        visited.clear();
        many = max(many,island);
    }
    
    cout << many;
}