#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9
int n;
vector < vector <int> >vec;
vector <bool> vis;
void solve(int start, int curr){

    vis[curr] = true;
    for(int i=0;i<n;i++){
        if(vis[i]==true)continue;
        if(vec[curr][i]==1){
            vec[start][i] = 1;
            solve(start,i);
        }
    }

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vec.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a; cin >> a;
            vec[i][j] = a;
        }
    }

    for(int i=0;i<n;i++){
        vis.resize(n,false);
        for(int j=0;j<n;j++){
           if(vec[i][j]==1){
               solve(i,j);
           }
        }
        vis.clear();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cout << vec[i][j] << " ";
        cout << "\n";
    }
}