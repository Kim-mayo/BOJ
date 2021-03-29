#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector <int> ans;
vector <int> arr;
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
        
        ans.push_back(arr[i]);
        backt();
       
        ans.pop_back();
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    visited.resize(n,false);
    sort(arr.begin(),arr.end());
    backt();
}