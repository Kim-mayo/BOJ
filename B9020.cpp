#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e9
bool prime[10001];
int main() {

	for (int i = 2; i < 10001; i++) prime[i] = true;
	for (int i = 2; i < 10001; i++) {//=다시생각해보기
		if (prime[i] == true) {
			for (int j = i * i; j < 10001; j += i) {
				prime[j] = false;
			}
		}
	}
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		int gap = INF;
		int num = 0;
		for (int i = 2; i <= n / 2; i++) {
			if (prime[i] == true && prime[n - i] == true) {
				if (gap > n - (2 * i)) {
					num = i;
					gap = n - (2 * i);
				}
			}
		}
		cout << num << " " << n - num << "\n";
	}

}