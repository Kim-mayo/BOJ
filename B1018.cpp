#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9
int n,m;
vector < vector < int > >board;
void solve(int row,int col){
    
    int change=0;
    for(int i=row;i<row+8;i++){
        for(int j=col;j<col+8;j++){
    
        }
    }

}
void input(){

    cin >> n >> m;
    board.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a; cin >> a;
            board[i].push_back(a);
        }
    }

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
}