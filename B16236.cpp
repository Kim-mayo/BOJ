#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n; 
vector < vector <int> > sea;
vector < vector <int> > vis;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int sharkSize=2;
int fishCatch;
int ans;
void findSec(int x,int y){

    vis.clear();
    vis.resize(n,vector<int>(n,-1));
    queue <pair <int,int> > q;
    q.push(make_pair(x,y));
    vis[x][y] = 0;
    //cout << ans << "\n";
    int fishr=-1,fishc=-1;
    int dis = 987654321;
    while(!q.empty()){

        int r = q.front().first;
        int c = q.front().second;
        int sec = vis[r][c];// cout << sec << "\n";
        q.pop();
        
        for(int i=0;i<4;i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(0<=nr&&nr<n&&0<=nc&&nc<n){
                if(vis[nr][nc]!=-1)continue;
                if(sharkSize>=sea[nr][nc]){
                    q.push(make_pair(nr,nc));
                    vis[nr][nc] = sec+1;
                    if(sea[nr][nc]==sharkSize)continue;
                    if(sea[nr][nc]==0)continue;
                    if(dis>vis[nr][nc]){
                        dis = vis[nr][nc];
                        fishr = nr; fishc = nc;
                    }
                    else if(dis==vis[nr][nc]){
                        if(fishr>nr){
                            fishr = nr; fishc = nc;
                        }
                        else if(fishr==nr){
                            if(fishc>c){
                                fishc = nc;
                            }
                        }
                    }
                }
            }
        }

    }
    
    if(fishr==-1||fishc==-1){
        ////////////여기서 출력해주면 되겠지////////////
        ////////////ans 출력하는 코드 넣어줘~ 사랑행///////////
        cout << ans;
        exit(0);
    }
    else {
        ans+=dis;
        fishCatch++;
        sea[fishr][fishc] = 0;
        if(fishCatch==sharkSize){
            sharkSize++; 
            //////////////여기 수정했음////////////
            fishCatch=0;
        }
        //cout << "###" << vis[fishr][fishc] << "\n";
        findSec(fishr,fishc);
    }

    return;
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    sea.resize(n,vector<int>(n,0));
    vis.resize(n,vector<int>(n,-1));
    int sx=0, sy=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a; cin >> a;
            if(a==9){
                sx = i;
                sy = j;
            }
            else if(a!=0){
                sea[i][j] = a;
            }
        }
    }
    findSec(sx,sy);
    //cout << ans;
}