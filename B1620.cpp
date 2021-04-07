#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

map <string,int> mp1;
map <int, string> mp2;

int main(){

    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++){
        string a; cin >> a;
        mp1[a] = i;
        mp2[i] = a;
    }
    for(int i=0;i<m;i++){
        string a; cin >> a;
        if('0'<=a[0]&&a[0]<='9'){
            int v = stoi(a);
            cout << mp2[v] << "\n";
        }
        else {
            cout << mp1[a] << "\n";
        }
    }
}
