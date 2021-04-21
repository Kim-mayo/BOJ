#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define mod %1000000009
int arr[100001][4];
void pre(){
    arr[1][1] = 1;
    arr[2][2] = 1;
    arr[3][1] = 1;
    arr[3][2] = 1;
    arr[3][3] = 1;
    for(int i=4;i<100001;i++){
        for(int j=1;j<4;j++){
            for(int k=1;k<4;k++){
                if(j==k)continue;
                arr[i][j] = (arr[i][j]mod + arr[i-j][k]mod)mod;
            }
        }
    }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans;
    pre();
    int t; cin >> t; 
    while(t!=0){

        ans = 0;
        int a; cin >> a;
        for(int i=1;i<4;i++){
            ans = ((ans)mod + arr[a][i]mod)mod;
        }
        cout << (ans)mod << "\n";

        --t;
    }

}