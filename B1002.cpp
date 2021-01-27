#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int t; cin >> t;
	for (int i = 0; i < t; i++) {

		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		if (x1 == x2 && y1 == y2 && r1 == r2) { cout << "-1\n"; continue; }
		if (abs(r1 - r2) < d && d < abs(r1 + r2)) cout << "2\n";
		else if (abs(r1 - r2) == d || abs(r1 + r2) == d) cout << "1\n";
		else cout << "0\n";


	}
}