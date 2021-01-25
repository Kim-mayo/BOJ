#include <iostream>
using namespace std;

int main() {

	while (true) {
		int A, B;
		int sum;

		cin >> A >> B;
		if (A == 0 && B == 0) break;
		sum = A + B;
		cout << sum << "\n";
	}

}