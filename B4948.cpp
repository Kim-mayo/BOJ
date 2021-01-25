#include <iostream>
#include <vector>
using namespace std;

int prime[300000];
int main() {//소수찾고, 소수갯수구하기

	for (int i = 2; i < 300000; i++) prime[i] = true;
	for (int i = 2; i * i < 300000; i++) {
		if (prime[i] == true) {
			for (int j = i * i; j < 300000; j += i) {
				prime[j] = false;
			}
		}
	}
	while (1) {

		int n; cin >> n;
		if (n == 0)return 0;
		int cnt = 0;
		for (int i = n+1; i <= 2*n; i++) {
			if (prime[i] == true) cnt++;
		}
		cout << cnt << "\n";
	}

}