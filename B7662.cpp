#include <iostream>
#include <map>
using namespace std;

map <int,int> mp;
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int i=0;i<t;i++){
        int k; cin >> k;
        for(int j=0;j<k;j++){
            char a; cin >> a;
            int b; cin >> b;
            if(a=='I'){
                if(mp.find(b)!=mp.end()){
                    map <int,int> ::iterator it = mp.find(b);
                    it->second++;
                }
                else{
                    mp.insert(make_pair(b,1));
                }
            }
            else if(a=='D'&&b==-1){
                if(mp.empty())continue;
                map <int,int> :: iterator it = mp.begin();
                it->second--; 
                int val = it->second;
                if(val==0){
                    mp.erase(it);
                }
            }
            else if(a=='D'&&b==1){
                if(mp.empty())continue;
                map <int,int> :: iterator it = --mp.end();
                it->second--;
                int val = it->second;
                if(val==0){
                    mp.erase(it);
                }
            }
        }
        if(mp.empty())cout << "EMPTY\n";
        else{
            map <int,int>::iterator it = mp.begin();
            map <int,int>::iterator it2 = --mp.end();
            cout << it2->first << " " << it->first << "\n";
        }
        mp.clear();
    }

}