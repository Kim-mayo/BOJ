#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector <int> arr;
vector <int> ans;
vector <bool> visited;
void backt(){

    if(ans.size()==m){
        for(int i=0;i<m;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(visited[i]==true)continue;
        visited[i]=true;
        ans.push_back(arr[i]);
        backt();
        visited[i]=false;
        ans.pop_back();
    }
    

    return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    visited.resize(n,false);
    for(int i=0;i<n;i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    backt();
}