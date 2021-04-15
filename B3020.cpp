#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> soon;
vector <int> jong;
vector <int> section;
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, h; cin >> n >> h;
    soon.resize(h+1);
    jong.resize(h+1);
    section.resize(h+1);
    for(int i=0;i<n;i++){
        int a; cin >> a;
        if(i%2==0){
            soon[a] += 1;
        }
        else jong[a] += 1;
    }

    for(int i=h-1;i>0;i--){
        soon[i] += soon[i+1];
        jong[i] += jong[i+1];
    }
    int small = 1e9;
    for(int i=1;i<=h;i++){
        section[i] = soon[i]+jong[h-i+1];
        small = min(small,section[i]);
    }
    cout << small << " ";
    int cnt=0;
    for(int i=1;i<=h;i++){
        if(section[i]==small)cnt++;
    }
    cout << cnt;
}