#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;

    vector<string>S;
    for(int i=0;i<s.size();i++){
        string tmp = "";
        for(int j=i;j<s.size();j++){
            tmp+=s[j];
           // cout << s[j] << " ";
        }
        //cout << "\n"
;        S.push_back(tmp);
    }
    sort(S.begin(),S.end());
    for(int i=0;i<S.size();i++){
        cout << S[i] << "\n";
    }
}