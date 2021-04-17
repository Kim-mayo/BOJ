#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, m; 
vector <int> vec;
unordered_map <string,bool> mp;
void solve(string ans,int np){

    if(ans.size()==m){
        //if(mp.find(ans)==mp.end()){
          //  mp[ans] = true;
          
            for(int i=0;i<m;i++){
                cout << ans[i]+'0' << " ";
            }
            cout << "\n";
            return;
        //}
        //return;
    }
    if(np==vec.size())return;

    solve(ans+char(vec[np]-'0'),np);
    solve(ans,np+1);
    return;

}
string pre = "";
void seol(int np, string ans){

    if(ans.size()==m){
        //if(pre==ans)return;
        for(int i=0;i<n;i++){
            cout << ans[i]+'0' << " ";
        }
        cout << "\n";
        pre = ans;
        return;
    }
    if(np == vec.size()){
        return;
    }

    seol(np,ans+char(vec[np]-'0'));
    seol(np+1,ans);
    
    return;
}
vector <int> ans;
void real(int start, int depth){
    if(depth==m){
        for(int i=0;i<m;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    int before = 0;
    for(int i=start;i<n;i++){
        if(before != vec[i]){
            before = vec[i];
            ans.push_back(vec[i]);
            real(i,depth+1);
            ans.pop_back();

        }
    }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    real(0,0);
   // vec.erase(unique(vec.begin(), vec.end()), vec.end());
   // seol(0,"");
    //solve("",0);
}