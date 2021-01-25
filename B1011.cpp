#include <iostream>
#include <algorithm>
using namespace std;

int universe(int x, int y) {

	int me = x + 1;
	int k = 1;
	int dis = 1;
	while (1) {

		if (me == y) break;

		int next = -1;
		if (k > 1 && me + k - 1 <= y && y - (me + k - 1) >= (k - 1) * (k - 2) / 2) next = me + k - 1;
		if (k > 0 && me + k <= y && y - (me + k) >= k * (k - 1) / 2) next = me + k;
		if (me + k + 1 <= y && y - (me + k + 1) >= (k + 1) * k / 2) next = me + k + 1;

		k = next - me;
		me = next;
		dis++;
	}

	return dis;
}
int main() {

	int t; cin >> t;
	for (int i = 0; i < t; i++) {

		int x, y; cin >> x >> y;
		cout << universe(x, y) << "\n";

	}

}