#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m; 
int year=1;
vector < vector <bool> > vis;
vector < pair <int ,int > > icecream;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
void part(vector<vector<int> >&sea, int x, int y){

    queue<pair<int,int> >q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        if(vis[currx][curry]==true)continue;
        vis[currx][curry] = true;
        for(int i=0;i<4;i++){
            int nx = currx + dx[i];
            int ny = curry + dy[i];
            if(0<=nx&&nx<n&&0<=ny&&ny<m){
                if(vis[nx][ny]==true)continue;
                if(sea[nx][ny]!=0){
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }

}
void Melt(vector<vector<int> >&sea){
 
    vector<int>melt;
    
   for(int i=0;i<icecream.size();i++){
       int x = icecream[i].first;
       int y = icecream[i].second;
       int melting = 0;
       for(int k=0;k<4;k++){
           int nx = x + dx[k];
           int ny = y + dy[k];
           if(0<=nx&&nx<n&&0<=ny&&ny<m){
               if(sea[nx][ny]==0)melting++;
           }
       }
       melt.push_back(melting);
   }
   
    vector<pair<int,int> > tmp;
    for(int i=0;i<icecream.size();i++){
        int x = icecream[i].first;
        int y = icecream[i].second;
        int m = melt[i];
        if(sea[x][y]-m>0){
            tmp.push_back(make_pair(x,y));
            sea[x][y] -= m;
        }
        else{sea[x][y] = 0;}
    }
    icecream=tmp;
   
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector < vector <int> > sea(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a; cin >> a;
            sea[i][j] = a;
            if(sea[i][j] > 0) icecream.push_back(make_pair(i,j));
        }
    }
    while(1){
        Melt(sea);
        int ice = 0;
        vis.clear();
        vis.resize(n,vector<bool>(m,false));

        for(int i=0;i<icecream.size();i++){
            int x = icecream[i].first;
            int y = icecream[i].second;
            if(vis[x][y]==false){
                part(sea,x,y);
                ice++;
            }
        }

        if(ice==0){
            cout << 0; break;
        }
        else if(ice>=2){
            cout << year; break;
        }
        else if(ice<2){
            year++;
        }
    }
 

}