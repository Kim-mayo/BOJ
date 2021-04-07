#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector < vector <int> >lab;
vector <pair <int,int> > virus;
vector <pair <int,int> > zero;
vector < vector <int> >vis;
int Bfs(){
    queue <pair <int,int> > q;
    vis.resize(n,vector<int>(m,-1));//방문전 -1, 방문후 2, 벽 1
    for(int i=0;i<virus.size();i++){
        q.push(make_pair(virus[i].first,virus[i].second));
        vis[virus[i].first][virus[i].second] = 2;
    }
    
    while(!q.empty()){
        int mer = q.front().first;
        int mec = q.front().second;
        q.pop();
       

        for(int i=0;i<4;i++){
            int nr = mer+dx[i];
            int nc = mec+dy[i];
            if(0<=nr&&nr<n&&0<=nc&&nc<m){
                if(vis[nr][nc]==2||vis[nr][nc]==1)continue;
                if(lab[nr][nc]==0){
                    if(vis[nr][nc]!=-1)continue;
                    vis[nr][nc] = 2;
                    q.push(make_pair(nr,nc));
                }
                else if(lab[nr][nc]==1)vis[nr][nc]=1;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==-1&&lab[i][j]==0)cnt++;
        }
    }
    vis.clear();
    return cnt;
}
int ANS;
void solve(){
    
    for(int i=0;i<zero.size();i++){
        lab[zero[i].first][zero[i].second] = 1;
        for(int j=i+1;j<zero.size();j++){
            lab[zero[j].first][zero[j].second] = 1;
            for(int k=j+1;k<zero.size();k++){
                lab[zero[k].first][zero[k].second]=1;
                ANS = max(ANS,Bfs());
                lab[zero[k].first][zero[k].second]=0;
            }
            lab[zero[j].first][zero[j].second]=0;
        }
     lab[zero[i].first][zero[i].second]=0;
    }
    return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    lab.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a; cin >> a;
            if(a==2)virus.push_back(make_pair(i,j));
            if(a==0)zero.push_back(make_pair(i,j));

            lab[i].push_back(a);
        }
    }
    solve();
    cout << ANS;

}