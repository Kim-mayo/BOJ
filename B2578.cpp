#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

#define INF 1e9
pair <int,int> Bingo[25];
int row[5] = {5,5,5,5,5};
int col[5] = {5,5,5,5,5};
int dae[2] = {5,5};
void input(){

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int a; cin >> a;
            Bingo[a] = make_pair(i,j);
        }
    }
    int bingo=0;
    int order=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int a; cin >> a;
            order++;
            int merow = Bingo[a].first;
            int mecol = Bingo[a].second;
            row[merow]--;
            if(row[merow]==0)bingo++;
            if(bingo==3) {cout << order; return;}
            col[mecol]--;
            if(col[mecol]==0)bingo++;
            if(bingo==3) {cout << order; return;}
            if(merow==mecol){
                dae[0]--;
               if(dae[0]==0)bingo++;
               if(bingo==3) {cout << order; return;}
            }
            if(merow+mecol==4){
                dae[1]--;
                if(dae[1]==0)bingo++;
                if(bingo==3) {cout << order; return;}
            }

            if(bingo==3) {cout << order; return;}
        }
    }

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    return 0;
}