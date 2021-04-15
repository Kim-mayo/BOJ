#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define inf 1e9
int n, m, k, start;
vector < vector <int> > city;
vector <int> dist;
void solve(int s){

    priority_queue <pair <int,int> > pq;
    pq.push(make_pair(0,s));
    while(!pq.empty()){

        int dis = -pq.top().first;
        int me = pq.top().second;
        pq.pop();
        if(dist[me]!=-1)continue;
        dist[me] = dis;
        for(int i=0;i<city[me].size();i++){
            int next = city[me][i];
            if(dist[next]!=-1)continue;
            //cout << me << " " << next << " " << dis+1 << "##\n";
            pq.push(make_pair(-(dis+1),next));
        }

    }

    // for(int i=1;i<=n;i++){
    //     cout << dist[i] << " ";
    // }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k >> start;
    city.resize(n+1);
    dist.resize(n+1,-1);
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b;
        city[a].push_back(b);
    }
    solve(start);
    bool ok = false;
    for(int i=1;i<=n;i++){
        if(dist[i]==k){
            cout << i << "\n";
            ok = true;
        }
    }
    if(ok==false)cout << "-1";
}