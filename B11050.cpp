#include <iostream>
using namespace std;

int main() {

	int a, b; cin >> a >> b;
	int num1 = 1;
	int num2 = 1;
	for (int i = 0; i < b; i++) {

		num1 *= (a - i);
		num2 *= (b - i);

	}
	cout << num1 / num2;

}