#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int i=0;i<n;i++){
        vector < int > sq;
        for(int j=0;j<10;j++){
            int a; cin >> a;
            sq.push_back(a);
        }
        sort(sq.begin(),sq.end());
        cout << sq[7] << "\n";
    }

}