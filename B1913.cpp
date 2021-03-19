#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

#define INF 1e9
vector < vector < int > > snail;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, num; cin >> n >> num;
    snail.resize(n,vector<int>(n,0));

    int me = n*n;
    int i=n-1;//밑에변
    int j=0;//왼쪽변
    int k=n-1;//오른쪽변
    int r=0;//위에변
   
    while(1){

       
        for(int q=j;q<=i;q++){
            snail[q][j] = me;     
            me--;
        }
        if(me==0)break;
        j++; 
        for(int q=j;q<=k;q++){
            snail[i][q] = me;
            me--;
        }
        if(me==0)break;
        i--;
        for(int q=i;q>=r;q--){
            snail[q][k] = me;
            me--;
        }
        if(me==0)break;
        k--;
        for(int q=k;q>=j;q--){
            snail[r][q] = me;
            me--; 
        }
        if(me==0)break;
        r++;
        
    }
    int rr=0,ll=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(snail[i][j]==num){rr=i;ll=j;}
            cout << snail[i][j] << " ";
        }
        cout << "\n";
    }
    cout << rr+1 << " " << ll+1;

    return 0;
}