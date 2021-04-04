#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){
        int num; cin >> num;
        if(num==0)return 0;

        vector<int>n;
        int N=num;
        while(1){
            if(N<1)break;
            n.push_back(N%10);
            N/=10;
        }
        bool ok=true;
        for(int i=0;i<n.size()/2;i++){
            if(n[i]!=n[n.size()-i-1])ok=false;
        }
        if(ok==true){cout << "yes\n";}
        else cout << "no\n";
    }
}