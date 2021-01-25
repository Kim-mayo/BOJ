#include <iostream>
#include <vector>
using namespace std;

int apart[14][15];
void miri() {
	for (int i = 0; i < 15; i++) {
		for (int j = 1; j <= 14; j++) {
			if (i == 0) {
				apart[i][j] = j; continue;
			}
			if (j == 1) {
				apart[i][j] = 1; continue;
			}
			apart[i][j] = apart[i][j - 1] + apart[i - 1][j];
		}
	}
}
int main() {
	int t; cin >> t;
	
	miri();
	for (int i = 0; i < t; i++) {
		int k, n; cin >> k >> n;
		cout << apart[k][n] << "\n";
	}
}