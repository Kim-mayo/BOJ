#include <iostream>
using namespace std;

int main() {
	int N; cin >> N;

	int s = 1000000;
	int B = -1000000;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;

		if (s > A) {
			s = A;
		}
		if (B < A) {
			B = A;
		}


	}

	cout << s << " " << B;
}