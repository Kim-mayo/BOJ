#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

long long a, b; 

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unordered_map < long long , int > mp;
    cin >> a >> b;

    mp[a] = 1;
    queue < long long > q;
    q.push(a);
    while (!q.empty()){
        long long curr = q.front();
        q.pop();
        if (curr == b) break;
        long long nx = curr * 2;
        if (nx <= b ){
            if (mp.find(nx) == mp.end()){
                mp[nx] = mp[curr] + 1;
                q.push(nx);
            }
        }
        nx = curr*10 +1;
        if (nx <=b){
            if( mp.find(nx) == mp.end()){
                mp[nx] = mp[curr] + 1;
                q.push(nx);
            }
        }
    }
    if(mp.find(b) == mp.end()){
        cout << -1;
    }
    else{
        cout << mp[b];
    }
}