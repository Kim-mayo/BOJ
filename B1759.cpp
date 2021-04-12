#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c; 
vector <char> vec; //
bool alp[200];
bool check(string c){
    int cnt1=0;
    int cnt2=0;
    for(int i=0;i<c.size();i++){
        if(cnt1>0&&cnt2>1)return true;
        if(c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u'){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }
    if(cnt1>0&&cnt2>1)return true;
    else return false;
}
void solve(string s,int idx){

    if(s.size()==l){
        if(check(s)){
            cout << s << "\n";
            return;
        }
        else return;
    }

    for(int i=idx;i<c;i++){
        solve(s+vec[i],i+1);
    }
    return;
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> l >> c;
    for(int i=0;i<c;i++){
        char a; cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    solve("",0);
}