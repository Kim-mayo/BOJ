#include <iostream>
using namespace std;

int main() {

	int t; cin >> t;
	for (int i = 0; i < t; i++) {

		int h, w, n; cin >> h >> w >> n;
		int col = (n / h)+1;
		int floor = n % h;

		int roomnum = 0;
		if (floor == 0) floor = h, col--;
		roomnum = floor * 100 + col;
		cout << roomnum << "\n";
	}

}