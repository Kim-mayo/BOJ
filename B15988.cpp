#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define mod %1000000009
int arr[1000001];
void pre(){

    arr[1]=1;
    arr[2]=2;
    arr[3]=4;

    for(int i=4;i<1000001;i++){
        arr[i] = ((arr[i-1]mod + arr[i-2]mod)mod + arr[i-3]mod)mod;
    }

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pre();

    int t; cin >> t;
    for(int i=0;i<t;i++){

        int a; cin >> a;
        cout << arr[a]mod << "\n";

    }

}