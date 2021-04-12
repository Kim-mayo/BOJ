#include <iostream>
#include <string>
#include <vector>
using namespace std;

int alp[27];
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    for(int i=0;i<s.size();i++){
        alp[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        cout << alp[i] << " ";
    }
}