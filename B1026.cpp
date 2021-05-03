#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int>A;
    vector<int>B;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        A.push_back(a);
    }
    for(int i=0;i<n;i++){
        int b; cin >> b;
        B.push_back(b);
    }
    sort(A.begin(),A.end());
    sort(B.rbegin(),B.rend());
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += A[i]*B[i];
    }
    cout << ans;
}