#include <iostream>
#include <algorithm>
using namespace std;
char castle[51][51];
int cava_row[51];
int cava_col[51];
int main() {

	int N, M; cin >> N >> M;
	int cavarow = 0;
	int cavacol = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> castle[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (castle[i][j] == 'X') cava_row[i] = 1;
			
		}
		if (cava_row[i] != 1) cavarow++;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (castle[j][i] == 'X') cava_col[i] = 1;
		}
		if (cava_col[i] != 1) cavacol++;
	}

	cout << max(cavacol, cavarow);

}