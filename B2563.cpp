#include <iostream>
using namespace std;

#define INF 1e9
bool paper[101][101];
int main(){

    int n; cin >> n;
    for(int i=0;i<n;i++){

        int sx,sy; cin >> sx >> sy;
        for(int j=sx;j<sx+10;j++){
            for(int k=sy;k<sy+10;k++){
                paper[j][k] = true;
            }
        }

    }

    int cnt=0;
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            if(paper[i][j]==true)cnt++;
        }
    }
    cout << cnt;

}