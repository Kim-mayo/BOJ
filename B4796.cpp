#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9
void input(){
    int k=1;    
    while(1){

        int l,p,v; cin >> l >> p >> v;
        if(l==0&&p==0&&v==0)return;

        int a = v/p;
        int b = v%p;
        if(b>l) b=l;
        int num = a*l + b;
        cout << "Case " << k << ": " << num << "\n";
        k++;
    }

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();

}