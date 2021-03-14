#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int sum; cin >> sum;
    int book=0;
    for(int i=0;i<9;i++){
        int a; cin >> a;
        book+=a;
    }
    cout << sum-book;

}