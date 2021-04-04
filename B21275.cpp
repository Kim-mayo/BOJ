#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a,b; cin >> a >> b;
    int aleast=-1;
    int bleast=-1;
    for(int i=0;i<a.size();i++){
        aleast = max((a[i]-'a'+10),aleast);
    }
    for(int i=0;i<b.size();i++){
        bleast = max((b[i]-'a'+10),bleast);
    }

}