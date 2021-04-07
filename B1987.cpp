#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n,m;
string board[20];
//int alp[27];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int big = -1;
void Dfs(int r,int c, int pick,int alp){
    
    big = max(pick,big);
 
    for(int i=0;i<4;i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(0<=nr&&nr<n&&0<=nc&&nc<m){
            int sq = board[nr][nc]-'A';
            if(!(alp&(1<<sq))){
                Dfs(nr,nc,pick+1,alp|(1<<sq));
            }

        }
    }
   
    return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        string a; cin >> a;
        board[i]+=a;
    }
    int sq = board[0][0]-'A';
    Dfs(0,0,1,(1<<sq));
    
    cout << big;
}