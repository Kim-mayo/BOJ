#include <iostream>
using namespace std;

int main() {

	int cnt = 0;
	int B = 0;
	for (int i = 0; i < 9; i++) {
		int A; cin >> A;
		if (B < A) {
			B = A; 
			cnt = i + 1;
		}
	}

	cout << B << "\n" << cnt;
}