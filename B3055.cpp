#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int R,C;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector < vector <char> > mp;
queue < pair <int,int> > qhog;
queue <pair <int,int> > qwater;
vector <vector <bool> > hogvis;
int Bfs(int r,int c){

    qhog.push(make_pair(r,c));
    int T=0;
    while(!qhog.empty()){
        T++;
        int wsize = qwater.size();
        for(int i=0;i<wsize;i++){
            int war = qwater.front().first;
            int wac = qwater.front().second;
            qwater.pop();
            for(int j=0;j<4;j++){
                int nx = war + dx[j];
                int ny = wac + dy[j];
                if(0<=nx&&nx<R&&0<=ny&&ny<C){
                    if(mp[nx][ny]=='*' ||mp[nx][ny]=='D')continue;
                    else if(mp[nx][ny]=='.'){
                        mp[nx][ny] = '*';
                        qwater.push(make_pair(nx,ny));
                    }
                }
            }
        }
        int hsize = qhog.size();
        for(int i=0;i<hsize;i++){
            int mer = qhog.front().first;
            int mec = qhog.front().second;
            qhog.pop();
            if(hogvis[mer][mec]==true)continue;
            hogvis[mer][mec]= true;
            for(int j=0;j<4;j++){
                int nx = mer + dx[j];
                int ny = mec + dy[j];
                if(0<=nx&&nx<R&&0<=ny&&ny<C){
                    if(mp[nx][ny]=='*')continue;
                    if(hogvis[nx][ny]==true)continue;
                    if(mp[nx][ny]=='D')return T;
                    else if(mp[nx][ny]=='.'){
                        qhog.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }
    return -1;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    mp.resize(R);
    hogvis.resize(R,vector<bool>(C,false));
    int startx=-1, starty=-1;
    int waterx=-1, watery=-1;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            char a; cin >> a;
            if(a=='S'){
                startx = i;
                starty = j; 
                a='.'; 
            }
            if(a=='*'){
               qwater.push(make_pair(i,j));
            }
            mp[i].push_back(a);
        }
    }
    int ans = Bfs(startx,starty);
    if(ans==-1){
        cout << "KAKTUS";
        return 0;
    }
    else {
        cout << ans;
    }


}