#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1e9;
int s[1000001];
void decom() {

    for (int i = 1; i < 1000001; i++) {
        int val = i;
        int desum = 0;
        while (val >0) {
            desum += val % 10;
            val = val / 10;
        }
        desum = desum + i;
        if (s[desum] == 0) {
            s[desum] = i;
        }
    }
}
int main() {

    int N; cin >> N;
 
    decom();
    cout << s[N];
 
 }