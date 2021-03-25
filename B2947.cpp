#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int arr[5];
    for(int i=0;i<5;i++){
        int a; cin >> a;
        arr[i] = a;
    }
    while(1){
    for(int i=0;i<4;i++){
        if(arr[i]>arr[i+1]){
            int tmp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = tmp;
            for(int i=0;i<5;i++)cout << arr[i] << " ";
            cout << "\n";
        }
    }
    bool ok = true;
    for(int i=0;i<5;i++){
        if(arr[i]!=i+1) ok = false;
    }
    if(ok!=false) break;
    }
}