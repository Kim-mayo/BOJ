#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n; 
vector <int> arr;
vector <bool> visited;
int big = -1e9;
void backt(int np,int value, int idx){

    if(np==n-1){
        big = max(big,value);
        return;
    }
  
    int val = arr[idx];
    for(int i=0;i<n;i++){
        if(visited[i]==true)continue;
        visited[i]=true;
      
        backt(np+1,value+abs(val-arr[i]),i);

        visited[i] = false;
    }
    
    return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    visited.resize(n,false);
    for(int i=0;i<n;i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    for(int i=0;i<n;i++){
        visited[i] = true;
        backt(0,0,i);
        visited[i] = false;
    }
    cout << big;
}