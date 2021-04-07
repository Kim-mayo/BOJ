#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector < vector <int> >fri;
void Floyd_washall(){

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(fri[i][j]>fri[i][k]+fri[k][j]){
                    fri[i][j] = fri[i][k] + fri[k][j];
                }
            }
        }
    }

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m; cin >> n >> m;
    fri.resize(n+1,vector<int>(n+1,1e9));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)fri[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b;
        fri[a][b] = 1;
        fri[b][a] = 1;
    }
    Floyd_washall();
    int ans = 1e9;
    int ANS = -1;
    for(int i=1;i<=n;i++){
        int sum =0;
        for(int j=1;j<=n;j++){
            sum+=fri[i][j];
        }
        if(ans>sum){
            ans = sum;
            ANS = i;
        }
    }
    cout << ANS;
}