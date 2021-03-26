#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int cnt[26];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string name; cin >> name;
    for(int i=0;i<name.size();i++){
        cnt[name[i]-'A']++;
    }
    int odd=0;
    int idx=-1;
    for(int i=0;i<26;i++){
        if(cnt[i]%2!=0){
            odd++;
            idx = i;
        }
    }
    if(name.size()%2!=0){
        odd--;
    }
    if(odd>0){
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<cnt[i]/2;j++){
            cout << char(i+'A');
        }
    }
    if(idx!=-1)cout << char(idx+'A');
    for(int i=25;i>=0;i--){
        for(int j=0;j<cnt[i]/2;j++){
            cout << char(i+'A');
        }
    }
    
}