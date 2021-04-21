#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int np=1;
vector<int>ans;
void solve(int num){
    
    if(num==n&&np!=k){
        np+=1;
        return;
    }
    if(num>n||np>k)return;
    if(num==n&&np==k){
        for(int i=0;i<ans.size();i++){
            if(i==ans.size()-1){cout << ans[i];break;}
            cout << ans[i] << "+";
        }
        exit(0);
    }

    for(int i=1;i<4;i++){
        ans.push_back(i);
        solve(num+i);
        ans.pop_back();
    }

    return;
}
int arr[11];
void pre(){

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i=4;i<11;i++)arr[i] = arr[i-1] + arr[i-2] + arr[i-3];

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pre();
    cin >> n >> k;
    if(arr[n]<k){
        cout << -1;
        return 0;
    }
    solve(0);

}