#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector <int> arr;
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    arr.resize(m+1);
    int size = n*2+1;
    string a; cin >> a;
    string b = a[0] + a;

    for(int i=1;i<=m;i++){
        if(b[i-1]==b[i]&&b[i]=='I')arr[i]=1;
        else if(b[i-1]==b[i]&&b[i]=='O')arr[i]=0;
        else if(b[i-1]!=b[i])arr[i] = arr[i-1]+1;
    }
    int ans=0;
    for(int i=0;i<=m;i++){
        if(arr[i]>arr[i+1]){
            if(arr[i]-size>=0){
                ans += (arr[i]-size)/2 + 1;
            }
        }
    }
    cout << ans;
}