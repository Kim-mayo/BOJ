#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define INF 1e9
vector < int > sq;
int visited[300000]; 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

   int A, P; cin >> A >> P;

    int num = A;
    visited[num] = 1;//(1-1)번에 num넣은거
    sq.push_back(num); 
    int stop=0;
    int idx=1;
    while(1){

        int curr = sq.back();
        int s = (int)to_string(curr).size();

        int next = 0;
       
        for(int i=0;i<s;i++){
            int a = curr%10;
            int val = 1;
            for(int j=0;j<P;j++){
                val*=a;
            }
            curr/=10;
            next+=val;
        }

        if(visited[next]!=0){
            stop = visited[next];
            break;
        }
        idx++;
        visited[next] = idx;
        sq.push_back(next);
    }

    cout << stop-1;

}