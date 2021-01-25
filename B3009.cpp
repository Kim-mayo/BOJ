#include <iostream>
using namespace std;

int x[3];
int y[3];
int main() {

	for (int i = 0; i < 3; i++) {
		int a, b; cin >> a >> b;
		x[i] = a;
		y[i] = b;
	}

	int a = 0, b = 0;
	if (x[0] == x[1]) a = x[2];
	else if (x[0] == x[2]) a = x[1];
	else a = x[0];

	if (y[0] == y[1]) b = y[2];
	else if (y[0] == y[2]) b = y[1];
	else b = y[0];

	cout << a << " " << b;

}