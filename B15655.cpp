#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int>arr;
vector<int>ans;
vector<bool>visited;
void backt(int idx){

    if(ans.size()==m){
        for(int i=0;i<m;i++)cout << ans[i] << " ";
        cout << "\n"; return;
    }
    for(int i=idx;i<n;i++){
        if(visited[i]==true)continue;
        visited[i]=true;
        ans.push_back(arr[i]);
        backt(i);
        ans.pop_back();
        visited[i]=false;
    }
    return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    visited.resize(n,false);
    backt(0);

}