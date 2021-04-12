#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b; cin >> a >> b;
    int h=0, m=0;
    if(b-45<0){
        
        m = 60 + (b - 45);
        if(a-1<0){
            h=23;
        }
        else h = a-1;
    }
    else{
        h = a;
        m = b - 45;
    }
    cout << h << " " << m;
}