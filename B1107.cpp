#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int small;
int sss;
bool button[10];//문제해결방법이해안댐 !!!!!!!!!!!!
vector <int> but;
void solve(int curr,int p){

    int ret = abs(curr - n) + p; 
    small = min(small,ret);
    if(sss==p)return;

    for(int i=0;i<but.size();i++){
        solve(curr*10+but[i],p+1);
    }

    return;

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m; cin >> n >> m;
    sss = to_string(n).size()+1;
    for(int i=0;i<m;i++){
        int a; cin >> a;
        button[a] = true;
    }
    for(int i=0;i<10;i++){
        if(button[i]==true)continue;
        but.push_back(i);
    }
    small = abs(n - 100);
    for(int i=0;i<but.size();i++){
        solve(but[i],1);
    }
    cout << small;
}