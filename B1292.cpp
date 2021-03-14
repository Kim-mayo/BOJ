#include <iostream>
#include <vector>
using namespace std;

vector<int>sq;
int main(){

    for(int i=1;i<1001;i++){
        for(int j=1;j<=i;j++){
            sq.push_back(i);
        }
    }
    int sum=0;
    int a,b; cin >> a >> b;
    for(int i=a-1;i<b;i++){
        sum += sq[i];
    }
    cout << sum;
}