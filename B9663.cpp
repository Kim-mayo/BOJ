#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int ans;
vector < pair < int,int > >saranghae;
bool queenCheck(int x, int y){
    for(int i=0;i<saranghae.size();i++){
        int qx = saranghae[i].first;
        int qy = saranghae[i].second;
        if(qy==y)return false;
        if(abs(qx-x)==abs(qy-y))return false;
    }
    return true;
}
void nQueen(int row){
    if(row==n){
        ans++;
        return;
    }
    for(int i=0;i<n;i++){
        if(queenCheck(row,i)){
            saranghae.push_back(make_pair(row,i));
            nQueen(row+1);
            saranghae.pop_back();
        }
    }
    return;
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    nQueen(0);
    cout << ans;

}