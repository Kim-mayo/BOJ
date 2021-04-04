#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <vector <int> >graph;
vector <bool> visited;
int cnt=0;
void Dfs(int me){
    if(visited[me]!=false)return;
    visited[me] = true;

    for(int i=0;i<graph[me].size();i++){
        int next = graph[me][i];
        Dfs(next);
    }

    
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    visited.resize(n+1,false); 
    bool ok =false;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(visited[i]==false){
            Dfs(i); cnt++;
        }
    }
    cout << cnt;
}