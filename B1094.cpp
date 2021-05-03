#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
 
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x; cin >> x;
   
    vector<int>bar;
    bar.push_back(64);
    int sum = 64;
    while(1){

        int shortBar = bar.back();
        bar.pop_back();
        sum -= shortBar;
        shortBar/=2;
        if(sum+shortBar>=x){
            bar.push_back(shortBar);
            sum += shortBar;
            if(sum==x)break;
        }
        else{
            bar.push_back(shortBar);
            bar.push_back(shortBar);
            sum += (shortBar)*2;
        }

    }
    

    cout << bar.size();
    
}