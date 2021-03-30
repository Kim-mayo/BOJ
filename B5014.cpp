#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int f,s,e,u,d;

vector < int > visited;
void Bfs(int a){

    queue <int > q;
    q.push(a);
    visited[a]=0;
    while(!q.empty()){

        int me = q.front();
        q.pop();
        int up = me+u;
        int dn = me-d;
        if(up<=f&&visited[up]==-1){
            visited[up] = visited[me]+1;
            q.push(up);
        }
        if(dn>0&&visited[dn]==-1){
            visited[dn] = visited[me]+1;
            q.push(dn);
        }
    }

}  
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> f >> s >> e >> u >> d;

    visited.resize(f+1,-1);
   Bfs(s);
    
    if(visited[e]==-1){cout << "use the stairs"; return 0;}
    cout << visited[e];
}