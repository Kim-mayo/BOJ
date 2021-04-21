#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[11];
void pre(){
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i=4;i<11;i++){
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pre();

    int t; cin >> t;
    while(t!=0){
        
        int a; cin >> a;
        cout << arr[a] << "\n";
        --t;
    }

}