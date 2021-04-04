#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> cd;
vector <int> me;
vector <int> ans;
int num[20000005];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        if(a>=0)num[a] += 1;
        else num[abs(a)+10000001]+=1;
    }
    int m; cin >> m;
    for(int i=0;i<m;i++){
        int a; cin >> a;
        if(a>=0){
            cout << num[a] << " ";
        }
        else cout << num[abs(a)+10000001] << " ";
    }
   

}