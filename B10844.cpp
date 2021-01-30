#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>stairs;
int main() {

	int n; cin >> n;
	stairs.resize(10, vector<int>(n, 1));
	stairs[0][0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) { stairs[j][i] = (stairs[j + 1][i - 1])%1000000000; continue; }
			if (j == 9) { stairs[j][i] = (stairs[j - 1][i - 1])%1000000000; continue; }
			stairs[j][i] = (stairs[j - 1][i - 1] + stairs[j + 1][i - 1])%1000000000;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += stairs[i][n - 1];
		sum %= 1000000000;
	}
	cout << sum;

}