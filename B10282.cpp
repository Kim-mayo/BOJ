#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector <vector <pair <int,int> > >net;
vector <int> dist;
void solve(int s,int N){
    
    dist.resize(N+1,-1);
    priority_queue <pair<int,int> > pq;
    pq.push(make_pair(0,s));
    while(!pq.empty()){

        int sec = -pq.top().first;
        int me = pq.top().second;
        pq.pop();
        if(dist[me]!=-1)continue;
        dist[me] = sec;
        for(int i=0;i<net[me].size();i++){
            int next = net[me][i].first;
            int nextSec = net[me][i].second;
            if(dist[next]!=-1)continue;
            pq.push(make_pair(-(nextSec+sec),next));
        }

    }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int i=0;i<t;i++){
        int n, d, start; cin >> n >> d >> start;
        net.resize(n+1);
        for(int j=0;j<d;j++){
            int a, b, c; cin >> a >> b >> c;
            net[b].push_back(make_pair(a,c));
        }
        solve(start,n);
        int computerN=0;
        int infectionSec=0;
        for(int i=1;i<=n;i++){
            if(dist[i]!=-1){
                computerN++;
                infectionSec = max(dist[i],infectionSec);
            }
        }
        cout << computerN << " " << infectionSec <<"\n";
        net.clear(); dist.clear();
    }
    
}