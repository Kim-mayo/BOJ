#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,k; 
int W; 
vector <int> t; //시간
vector <vector <int> > order; //연결상태
vector <int> dp; 
vector <int> topo; //위상
void solve(){

    queue <pair <int,int> >q;
    for(int i=1;i<=n;i++){
        if(topo[i]==0){
            q.push(make_pair(i,t[i]));
        }
    }

    while(!q.empty()){

        int curr = q.front().first;
        int currt = q.front().second;
        dp[curr] += currt; 
        q.pop();
        for(int i=0;i<order[curr].size();i++){
            int next = order[curr][i];
            int nextt = t[order[curr][i]];

            dp[next] = max(dp[next],dp[curr]);
            topo[next]--;

            if(topo[next]==0){
                q.push(make_pair(next,nextt));
            }
        }

    }
    //for(int i=1;i<=n;i++)cout << dp[i] << " ";

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    for(int q=0;q<tc;q++){

        cin >> n >> k;
        t.resize(n+1);
        dp.resize(n+1,0);
        topo.resize(n+1,0);
        for(int i=1;i<=n;i++){
            int a; cin >> a;
            t[i] = a;
        }
        order.resize(n+1);
        for(int i=0;i<k;i++){
            int a, b; cin >> a >> b;
            order[a].push_back(b);
            topo[b]+=1;
        }
        cin >> W;
        solve();
        cout << dp[W] << "\n";
        dp.clear(); topo.clear(); order.clear(); t.clear();
        
    }

}