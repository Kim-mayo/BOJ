#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	
	while (1) {

		int tri[3];
		for (int i = 0; i < 3; i++) {
			int a; cin >> a;
			tri[i] = a;
		}
		sort(tri, tri + 3);
		if (tri[0]==0&&tri[1]==0&&tri[2]==0) return 0;
		if (sqrt(pow(tri[0], 2) + pow(tri[1], 2)) == sqrt(pow(tri[2], 2))) {
			cout << "right\n";
		}
		else cout << "wrong\n";

	}

}