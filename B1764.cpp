#include <iostream>
#include <unordered_set>
#include <vector>
#include <set>
using namespace std;

unordered_set <string> mp;
set <string > vec;
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m; 
    for(int i=0;i<n;i++){
        string a; cin >> a;
        mp.insert(a);
    }
    for(int i=0;i<m;i++){
        string a; cin >> a;
        if(mp.find(a)!=mp.end()){
            vec.insert(a);
        }
    }
    cout << vec.size() << "\n";

    for(auto it=vec.begin();it!=vec.end();it++){
        cout << *it<<"\n";
    }

}