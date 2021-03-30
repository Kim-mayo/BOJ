#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector < vector < int > > fam;
vector <int> visited;
int n,s,e,m;
int chon;
bool ok = false;
int Bfs(int a){
    queue <int >q;
    q.push(a);

    while(!q.empty()){
        int qs = q.size();
        for(int seol=0;seol<qs;seol++){
        int me = q.front();

        q.pop();
        if(visited[me]==true){continue;}
        visited[me] = true;
        for(int i=0;i<fam[me].size();i++){
            int nt = fam[me][i];
            if(nt==e){return chon+1;}
            if(visited[nt]==true)continue;
            q.push(nt);
        }
       
        }
        chon++;
    }
   
    return -1;

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s >> e >> m;
    fam.resize(n+1);
    visited.resize(n+1,false);
    for(int i=0;i<m;i++){

        int a,b; cin >> a >> b;
        fam[a].push_back(b);
        fam[b].push_back(a);

    }
   cout << Bfs(s);
}