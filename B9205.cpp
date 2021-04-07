#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

vector <bool> visited;
vector <pair<int,int > > beer;
bool solve(){

    queue <int> q;
    q.push(0);
    while(!q.empty()){

        int me = q.front();//cout << me << " ";
        if(me==beer.size()-1)return true;
        q.pop();
        if(visited[me]==true)continue;
        visited[me] = true;
        int mex = beer[me].first;
        int mey = beer[me].second;
        for(int i=0;i<beer.size();i++){
            if(visited[i]==true)continue;
            int nx = beer[i].first;
            int ny = beer[i].second;

            if(abs(nx-mex)+abs(ny-mey)<=1000){
                q.push(i);
            }
        }
    }

    return false;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;//맥주20병 들고 시작, 50미터당 1병소비
    for(int t=0; t<tc; t++){
        int cn; cin >> cn;//편의점갯수
        int hx,hy; cin >> hx >> hy; //집좌표
        beer.push_back(make_pair(hx,hy));
        for(int i=0;i<cn;i++){
            int a, b; cin >> a >> b; //편의점좌표
            beer.push_back(make_pair(a,b));
        }
        int rx, ry; cin >> rx >> ry; //락페좌표
        beer.push_back(make_pair(rx,ry));
        visited.resize(beer.size(),false);
        if(solve()) cout << "happy\n";
        else cout << "sad\n";
        beer.clear(); visited.clear();
    }

}