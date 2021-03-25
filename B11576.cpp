#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 1e9
int a,b; 
queue < int > sq;
vector < int > answer;
void solve(){

    int ten=0;
    int s = sq.size();
    for(int i=0;i<s;i++){
        int mul=1;
        for(int j=s-1-i;j>0;j--){
            mul *=a;
        }
        ten += sq.front()*mul;
        sq.pop();
    }
    int size = to_string(ten).size();
    
    while(1){

        int u = ten/b;
        int v = ten%b;
        answer.push_back(v);
        if(u<b){
            answer.push_back(u);
            break;
        }
        else{
            ten = u;
        }

    }
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    int m; cin >> m;
    for(int i=0;i<m;i++){
        int a; cin >> a;
        sq.push(a);
    }

    solve();
    for(int i=answer.size()-1;i>=0;i--){
        cout << answer[i] << " ";
    }
}