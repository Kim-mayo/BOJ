#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <bool> visited;
vector <int> Array;
void backt(vector<int>arr){

    if(arr.size()==n){
        for(int i=0;i<n;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=n;i++){

        if(visited[i]==true)continue;
        visited[i]=true;
        arr.push_back(i);
        backt(arr);
        arr.pop_back();
        visited[i]=false;

    }
    return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    visited.resize(n,false);
    backt(Array);

}