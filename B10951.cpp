#include <iostream>
using namespace std;

int main() {

	while (1) {
		int A, B, sum=0;

		cin >> A;
		if (cin.eof() == true) break;

		cin >> B;
		sum = A + B;
		cout << sum << "\n";
	}

}