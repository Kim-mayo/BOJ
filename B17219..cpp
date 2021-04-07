#include <iostream>
#include <map>
#include <string>
using namespace std;

map <string,string> mp;
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++){
        string a,b; cin >> a >> b;
        //cout << a << " " << b << "\n";
        mp[a] = b;
    }
    for(int i=0;i<m;i++){
        string a; cin >> a;
        cout << mp.find(a)->second << "\n";
    }

}