#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector <int> arr;
vector <int> rank;
priority_queue < pair <int,int> > pq;
void solve(){

    int RANK = 0;
    while(!pq.empty()){

        int val = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        arr[idx] = RANK;
        if(pq.top().first==val){
            //cout << RANK << pq.top().first << pq.top().second << val;
            while(pq.top().first==val&&!pq.empty()){
                int index = pq.top().second;
                pq.pop();
                arr[index] = RANK;
            }
        }
       
        RANK++;

    }

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        arr.push_back(a);
        pq.push(make_pair(-a,i));
    }
    solve();
    for(int i=0;i<n;i++){
        cout << arr[i] << " "; 
    }
}