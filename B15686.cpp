#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m; 
int ans = 1e9;
vector <pair <int,int> > chicken;
vector <pair <int,int> > house;
vector <pair <int,int> > selectChicken;
void measureDis(){

    int ret =0;
    for(int i=0;i<house.size();i++){
        int sum = 1e9;
        int hx = house[i].first;
        int hy = house[i].second;
        for(int j=0;j<m;j++){
            int cx = selectChicken[j].first;
            int cy = selectChicken[j].second;

            sum = min(sum,abs(hx-cx) + abs(hy-cy));
        }
        ret += sum;
    }
    ans = min(ret,ans);
    return;
}
void chooseChicken(int np){
    
    for(int i=0;i<selectChicken.size();i++){
        cout << selectChicken[i].first << " "; 
    }
    cout << " #### \n";
    if(selectChicken.size()==m){
        measureDis();
        return;
    }
    for(int i=np;i<chicken.size();i++){
        selectChicken.push_back(make_pair(chicken[i].first,chicken[i].second));
        chooseChicken(i+1);
        selectChicken.pop_back();
    }
    return;
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a; cin >> a;
            if(a==1){
                house.push_back(make_pair(i,j));
            }
            else if(a==2){
                chicken.push_back(make_pair(i,j));
            }
        }
    }
    chooseChicken(0);
    cout << ans;
}