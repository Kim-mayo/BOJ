#include <iostream>
#include <algorithm>
using namespace std;

int op[4];// + - * /
int num[12];
int trace[12][4];
int n;
int big = -1000000001;
int small = 1000000001;
int Backtracking(int np, int value) {

	if(np==n){
		big = max(big, value);
		small = min(small, value);
		return big;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] == 0)continue;

		op[i]--;
		if (i == 0) {
			int v = Backtracking(np + 1, value + num[np]);
			trace[np][0] = max(v,trace[np][0]);
		}
		else if (i == 1) {
			Backtracking(np + 1, value - num[np]);
		}
		else if (i == 2) {
			Backtracking(np + 1, value * num[np]);
		}
		else {
			if (value < 0) {
				Backtracking(np + 1, -(-value / num[np]));
			}
			else {
				Backtracking(np + 1, value / num[np]);
			}
		}
		op[i]++;
	}
	return;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		num[i] = a;
	}
	for (int i = 0; i < 4; i++) {
		int a; cin >> a;
		op[i] = a;
	}
	Backtracking(1, num[0]);
	cout << big << "\n" << small << "\n";
}