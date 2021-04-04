#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define mod %1234567891
vector<long long>num;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string a; cin >> a;
    for(int i=0;i<n;i++){
        int number = a[i]-'a'+1;
        long long mul=1; int p = i;
        while(p!=0){
            mul = ((mul)mod * 31)mod;
            p--;
        }
        num.push_back((number*mul)mod);
    }
    long long ans=0;
    for(int i=0;i<num.size();i++){
        ans = ((ans)mod + (num[i])mod)mod;
    }
    cout << ans;
}