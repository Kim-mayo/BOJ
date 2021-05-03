#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int n, m; 
vector < vector <char> > board;
int vis[11][11][11][11];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void Tilt(int rx, int ry, int bx, int by){

    queue <pair<int,int> > qr;
    queue <pair<int,int> > qb;
    qr.push(make_pair(rx,ry));
    qb.push(make_pair(bx,by));
    int ans = 0;

    while(!qr.empty()){
        int qs = qr.size();
        if(ans==10) break;
        ans++;
        while(qs--){
            
            int redx = qr.front().first;
            int redy = qr.front().second;
            int bluex = qb.front().first;
            int bluey = qb.front().second;
            qr.pop(); qb.pop();
            if(vis[redx][redy][bluex][bluey]!=-1)continue;
            vis[redx][redy][bluex][bluey] = 1;
            cout << redx << " " << redy << " " << bluex << " " << bluey << "\n";
            for(int i=0;i<4;i++){
                bool REDBALL = false;
                bool BLUEBALL = false;
                cout << i << "\n";
                int nrx = redx;
                int nry = redy;
                int nbx = bluex;
                int nby = bluey;
                int R=0,B=0;
                
                while(1){
                    if(0<=nrx&&nrx<n&&0<=nry&&nry<m){
                        if(board[nrx][nry]=='#'){
                            nrx -= dx[i];
                            nry -= dy[i];
                            break;
                        }
                        else if(board[nrx][nry]=='O'){
                            REDBALL = true;
                            break;
                        }
                        else{
                            R++;
                            nrx += dx[i];
                            nry += dy[i];
                        }
                    }
                    else break;
                }
                while(1){
                    if(0<=nbx&&nbx<n&&0<=nby&&nby<m){
                        if(board[nbx][nby]=='#'){
                            nbx -= dx[i];
                            nby -= dy[i];
                            break;
                        }
                        else if(board[nbx][nby]=='O'){
                            BLUEBALL = true;
                            break;
                        }
                        else {
                            B++;
                            nbx += dx[i];
                            nby += dy[i];
                        }
                    }
                    else break;
                }
              
                if(REDBALL&&!BLUEBALL){
                    cout << ans; return;
                }
                if(REDBALL&&BLUEBALL)continue;
                cout << nrx << " " << nry << " " << nbx << " " << nby << "!!\n";
                if(nrx==nbx&&nry==nby){
                    
                    if(R>B){
                        //cout << nrx-dx[i] << " " << nry-dy[i] << " " << nbx << " " << nby << "1\n";
                        if(vis[nrx-dx[i]][nry-dy[i]][nbx][nby]!=-1)continue;
                        qr.push(make_pair(nrx-dx[i],nry-dy[i]));
                        qb.push(make_pair(nbx,nby));
                    }
                    else {
                        //cout << nrx << " " << nry << " " << nbx-dx[i]<< " " << nby-dy[i]<< "2\n";
                        if(vis[nrx][nry][nbx-dx[i]][nby-dy[i]]!=-1)continue;
                        qr.push(make_pair(nrx,nry));
                        qb.push(make_pair(nbx-dx[i],nby-dy[i]));//이게 레인지오버 날수도있나??
                    }
                }
                else{
                    if(vis[nrx][nry][nbx][nby]!=-1)continue;
                    qr.push(make_pair(nrx,nry));
                    qb.push(make_pair(nbx,nby));
                }
            }
        }
    }
    cout << -1; return;

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    memset(vis,-1,sizeof(vis));
    board.resize(n,vector<char>(m));
    pair <int,int> blue,red;
    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           char a; cin >> a;
           board[i][j] = a;
           if(a=='B')blue = make_pair(i,j), board[i][j] = '.';
           if(a=='R')red = make_pair(i,j), board[i][j] = '.';
       }
    }
    Tilt(red.first,red.second,blue.first,blue.second);
}