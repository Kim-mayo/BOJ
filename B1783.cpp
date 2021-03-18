#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9
int n,m;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    if(n==1){cout << "1"; return 0;}
    if(n==2){cout << min(4,((m+1)/2)); return 0;}
    if(n>=3){

        if(m<=6){cout << min(4,m); return 0;}
        cout << m-2;

    }

}