#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>presum;
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    int sum=0;
    presum.push_back(0);
    for(int i=0;i<n;i++){
        int a; cin >> a;
        sum+=a; 
        presum.push_back(sum);
    }
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b;
        cout << presum[b]-presum[a-1] << "\n";
    }
}