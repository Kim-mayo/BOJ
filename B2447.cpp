#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>>sky;
void Star(int sx, int sy, int n, bool space) {

	if (space) {
		for (int i = sx; i < sx + n; i++) {
			for (int j = sy; j < sy + n; j++) {
				sky[i][j] = ' ';
			}
		}
		return;
	}
	if (n == 1) return;

	Star(sx, sy, n / 3, false);
	Star(sx, sy + n / 3, n / 3, false);
	Star(sx, sy + 2 * n / 3, n / 3, false);
	Star(sx + n / 3, sy, n / 3, false);
	Star(sx + n / 3, sy + n / 3, n / 3, true);
	Star(sx + n / 3, sy + 2 * n / 3, n / 3, false);
	Star(sx + 2 * n / 3, sy, n / 3, false);
	Star(sx + 2 * n / 3, sy + n / 3, n / 3, false);
	Star(sx + 2 * n / 3, sy + 2 * n / 3, n / 3, false);

	return;
}
int main() {
	int N; cin >> N;
	sky.resize(N, vector<char>(N, '*'));

	Star(0, 0, N, false);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << sky[i][j];
		}
		cout << "\n";
	}
}