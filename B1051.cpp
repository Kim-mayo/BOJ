#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9
int s;
int width;
int n,m; 
vector < vector < int > > sq;
int solve(){

    while(s>1){

        for(int i=0;i<n;i++){
            if(i+s-1>=n) break;
            for(int j=0;j<m;j++){
                if(j+s-1>=m)break;
                if(sq[i][j]==sq[i+s-1][j]&&sq[i+s-1][j]==sq[i][j+s-1]&&sq[i][j+s-1]==sq[i+s-1][j+s-1]){
                    width = s*s;
                }

            }
        }


        if(width == 0){
        s--;
        }
        else break;
    }
    if(width==0)width=1;
    return width;

}
void input(){

    cin >> n >> m;
    sq.resize(n);
    s = min(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a; cin >> a;
            sq[i].push_back(a-'0');
        }
    }

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    cout << solve();
}