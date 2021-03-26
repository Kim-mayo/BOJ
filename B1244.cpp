#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < int > sq;
void solve(int se, int num){
    if(se==1){//님
        for(int i=num;i<sq.size();i+=num){
            if(sq[i]==0)sq[i]=1;
            else sq[i]=0;
        }
    }
    else{//여
        if(sq[num]==0)sq[num]=1;
        else sq[num]=0;
        for(int i=1;i<sq.size();i++){
            if(0<num-i&&num+i<sq.size()){
                if(sq[num+i]==sq[num-i]){
                    if(sq[num+i]==0){
                        sq[num+i]=1;
                        sq[num-i]=1;
                    }
                    else{
                        sq[num+i]=0;
                        sq[num-i]=0;
                    }
                }
                else break;
            }
        }
    }
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    sq.push_back(-1);
    for(int i=0;i<n;i++){
        int a; cin >> a;
        sq.push_back(a);
    }
    int k; cin >> k;
    for(int i=0;i<k;i++){
        int a,b; cin >> a >>b;
        solve(a,b);
    }
    for(int i=1;i<=n;i++){
        cout << sq[i] << " ";
        if(i%20==0)cout << "\n";
    }

}