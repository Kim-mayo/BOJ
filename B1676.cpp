#include <iostream>
using namespace std;

int main() {

	int n; cin >> n;
	int sum = 0;
	while (1) {

		if (n == 0) break;
		sum += n / 5;
		n=n / 5;

	}
	cout << sum;
}