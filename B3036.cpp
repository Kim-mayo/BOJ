#include <iostream>
using namespace std;

int gcf(int a, int b) {
	return b ? gcf(b, a % b) : a;
}
int main() {

	int n; cin >> n;
	int numer; cin >> numer;
	for (int i = 1; i < n; i++) {
		int denom; cin >> denom;

		int f= gcf(numer, denom);
		cout << numer / f << "/" << denom / f << "\n";
	}

}