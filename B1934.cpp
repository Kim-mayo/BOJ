#include <iostream>
using namespace std;

int gcf(int a, int b) {
	return b ? gcf(b, a % b) : a;
}
int main() {

	int t; cin >> t;
	for (int i = 0; i < t; i++) {

		int a, b; cin >> a >> b;
		int f = gcf(a, b);
		cout << (a * b) / f << "\n";
	}

}