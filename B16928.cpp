#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int game[101];
bool vis[101];
int ret=1e9;
int solve(){
    queue <pair <int, int> >q;
    q.push(make_pair(1,0));
    vis[1] = true;
    while(!q.empty()){
        int fr = q.front().first;
        int move = q.front().second;
        q.pop();
        
        if(fr==100){
          return move;
        }
        for(int i=1;i<=6;i++){
            if(fr+i>100)break;
            if(game[fr+i]!=0){
                if(vis[game[fr+i]]==true)continue;
                q.push(make_pair(game[fr+i],move+1));
                vis[game[fr+i]] = true;
            }
            else{
                if(vis[fr+i]==true)continue;
                q.push(make_pair(fr+i,move+1));
                vis[fr+i] = true;
            }
           
        
        }
    }
    return ret;
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++){
        int a, b; cin >> a >> b;
        game[a] = b;
    }
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b;
        game[a] = b;
    }
    cout << solve();
}