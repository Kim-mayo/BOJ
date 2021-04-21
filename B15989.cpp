#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[4][10001];
void pre(){

    arr[1][1] = 1;
    arr[1][2] = 1;
    arr[1][3] = 2;
    arr[2][2] = 1;
    arr[3][3] = 1;
    for(int i=4;i<10001;i++){
        for(int j=1;j<4;j++){
            for(int k=j;k<4;k++){
                arr[j][i] += arr[k][i-j];
            }
        }
    }

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pre();
    int t; cin >> t;
    while(t!=0){

        int ans =0;
        int a; cin >> a;

        for(int i=1;i<4;i++){
            ans += arr[i][a];
        }
        cout << ans << "\n";
        --t;

    }

}