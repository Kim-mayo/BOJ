#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define l long long
vector <l> tree;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    l n,m; cin >> n >> m;
    l e=-1;
    for(int i=0;i<n;i++){
        l a; cin >> a;
        tree.push_back(a);
        e = max(e,a);
    }    
    l start = 0;
    l end = e+1;
    l ans=-1;
    while(1){
        if(start>=end)break;
        l mid = (start+end)/2;
        l sum=0;
        for(int i=0;i<n;i++){
            l s = tree[i]-mid;
            if(s<=0) s=0;
            sum+=s;
        }
        if(sum>=m){
            ans = mid;
            start = mid+1;
        }
        else {
            end = mid;
        }
    }
    cout << start-1;
  
}