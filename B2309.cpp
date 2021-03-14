#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dwarf[10];
bool visited[10];
vector<int>selected;
bool e;
int solve(int sum){

    if(sum>100)return 0;
    if(selected.size()==7){
        if(sum==100){
            sort(selected.begin(),selected.end());
            for(int i=0;i<7;i++)cout << selected[i] << "\n";
            exit(0);
        }
    }
    if(sum<100){

        for(int i=0;i<10;i++){
            if(visited[i]==true)continue;
            visited[i]=true;
            sum += dwarf[i];
            selected.push_back(dwarf[i]);
            solve(sum);
            visited[i] = false;
            selected.pop_back();
            sum -=dwarf[i];
        }

    }
    return 0;
}
int main(){

    for(int i=0;i<10;i++){
        int a; cin >> a;
        dwarf[i] = a;
    }
    solve(0);

}