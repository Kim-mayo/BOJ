#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[10001];
string solve(int s, int e){

    queue < pair <int,string> >q;
    q.push(make_pair(s,""));
    visited[s] = true;
    while(!q.empty()){
        int me = q.front().first;
        string How = q.front().second;
        if(me==e)return How;
        q.pop();
        int D = (me*2)%10000;
        int S = (me+9999)%10000;
        int mok = me/1000;  int na = me%1000;
        int L = na*10+mok;
        int mok2 = me/10; int na2 = me%10;
        int R = na2*1000+mok2;
        if(visited[D]==false){
            q.push(make_pair(D,How+'D'));
            visited[D] = true;
        }
        if(visited[S]==false){
            q.push(make_pair(S,How+'S'));
            visited[S] = true;
        }
        if(visited[L]==false){
            q.push(make_pair(L,How+'L'));
            visited[L] = true;
        }
        if(visited[R]==false){
            q.push(make_pair(R,How+'R'));
            visited[R] = true;
        }
    }
   return "";
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int t; cin >> t;
    for(int i=0;i<t;i++){
        for(int j=0;j<10001;j++)visited[j]=false;
        int a,b; cin >> a >> b;
        cout << solve(a,b) << "\n";
    }

}