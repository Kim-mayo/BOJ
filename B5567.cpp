#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 1e9
vector < vector < int > >fri;
bool visited[501];
int n,m;
queue < int > q;
int ans;
void solve(){

    visited[1] = true;
    for(int i=0;i<fri[1].size();i++){
        q.push(fri[1][i]);
        visited[fri[1][i]] = true;
        ans++;
    }

    while(!q.empty()){

        int curr = q.front();
        q.pop();
        for(int i=0;i<fri[curr].size();i++){
            int next = fri[curr][i];
            if(visited[next] == true)continue;
            if(visited[next]!=true)ans++;
           
        }

    }


}
void input(){

    cin >> n >> m;
    fri.resize(n+1);
    for(int i=0;i<m;i++){

        int a,b; cin >> a >> b;
        fri[a].push_back(b);
        fri[b].push_back(a);

    }

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solve();
    cout << ans;
}