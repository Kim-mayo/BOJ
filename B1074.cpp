#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int val;
int r, c;
void solve(int row,int col, int size){

    if(size==1){
        if(row==r&&col==c){
            cout << val;
            exit(0);
        }
        return;
    }
    if(row<=r&&r<row+size/2&&col<=c&&c<col+size/2){
        solve(row,col,size/2);
    }
    else val += (size*size/4);
    if(row<=r&&r<row+size/2&&col+size/2<=c&&c<col+size){
        solve(row,col+size/2,size/2);
    }
    else val += (size*size/4);
    if(row+size/2<=r&&r<row+size&&col<=c&&c<col+size/2){
        solve(row+size/2,col,size/2);
    }
    else val += (size*size/4);
    if(row+size/2<=r&&r<row+size&&col+size/2<=c&&c<col+size){
        solve(row+size/2,col+size/2,size/2);
    }
    else val += (size*size/4);

    return;
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N >> r >> c;
    int NNN = 1<<N;
    solve(0,0,NNN);
    
}