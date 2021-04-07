#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, k;
vector < vector < int > > sq;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void Dfs(int row, int col, int group){

    if(sq[row][col]!=0) return;
    sq[row][col] = group;

    for(int i=0;i<4;i++){
        int nr = row+dx[i];
        int nc = col+dy[i];
        if(0<=nr&&nr<R&&0<=nc&&nc<C){
            if(sq[nr][nc]!=0)continue;
            Dfs(nr,nc,group);
        }
    }
    return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> C >> R >> k;
    sq.resize(R,vector<int>(C,0));// 방문전 0, 방문후 그룹번호, 갈수없음 -1
    for(int t=0;t<k;t++){
        int a,b,c,d; cin >> a >> b >> c >> d;
        for(int i=a;i<c;i++){
            for(int j=b;j<d;j++){
                sq[i][j] = -1;
            }
        }
    }
    int cnt=0, g=1;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(sq[i][j]==0){
                Dfs(i,j,g);
                cnt++; g++;
            }
        }
    }
    cout << cnt << "\n";
    vector <int > ANS;
    ANS.resize(g,0);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(sq[i][j] == -1) continue;
            ANS[sq[i][j]] +=1;
        }
    }
    sort(ANS.begin(),ANS.end());
    for(int i=1;i<ANS.size();i++)cout << ANS[i] << " ";

}