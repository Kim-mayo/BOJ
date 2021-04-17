#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<int>vis;
vector<int>dp;
vector < int > inque;
int SEC;
int cnt;
queue <int> qq;
void Dp(int num){

    if(num==n){
        cnt++;
        return;
    }
    if(num-1>=0&&vis[num-1]+1==vis[num]){
        Dp(num-1);
    }
    if(num+1<200000&&vis[num+1]+1==vis[num]){
        Dp(num+1);
    }
    if(num%2==0&&vis[num/2]+1==vis[num]){
        Dp(num/2);
    }

    return;
}
void solve(int sec, int pos){
    
    vis.resize(200000,-1);
    queue <pair<int,int> > q;
    q.push(make_pair(sec,pos));
    while(!q.empty()){

        int cho = q.front().first;
        int curr = q.front().second;
        q.pop();
        if(vis[curr]!=-1)continue;
        vis[curr] = cho;
        
        if(curr==m){
            SEC = cho;
            break;
        }
        
        int nc1 = curr+1;
        if(nc1<200000&&vis[nc1]==-1){
            q.push(make_pair((cho+1),nc1));
        }
        int nc2 = curr-1;
        if(nc2>=0&&vis[nc2]==-1){
            q.push(make_pair((cho+1),nc2));
        }
        int nc3 = curr*2;
        if(nc3<200000&&vis[nc3]==-1){
            q.push(make_pair((cho+1),nc3));
        }
    }
    cout << SEC << "\n";
    return;
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inque.resize(200000,0);
    cin >> n >> m;
    if(n==m){
        cout << 0 << "\n" << 1;
        return 0;
    }
    solve(0,n);
    //for(int i=0;i<35;i++)cout << i << ":" << vis[i] << " ";
    //dp.resize(200000,0);
    Dp(m);
    cout << cnt;
  
}