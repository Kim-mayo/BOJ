#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n,m;
vector <int> arr;
vector <int> ans;
vector <bool> visited;
set <string> st;
int fir=-1;
void backt(string s){

    if(ans.size()==m){
       if(st.find(s)!=st.end())return;
       for(int i=0;i<m;i++){
           cout << ans[i] << " ";
       }
       cout << "\n";
       st.insert(s);
       return;
    }
    for(int i=0;i<n;i++){
        if(visited[i]==true)continue;
        visited[i]=true;
        ans.push_back(arr[i]);
        backt(s+to_string(arr[i]));
        ans.pop_back();
        visited[i]=false;
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
    backt("");

}