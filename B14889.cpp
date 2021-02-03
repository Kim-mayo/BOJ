#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>stats;
bool used[21];
int n;
int cha = 987654321;
void backtracking(int curr,int cnt) {

	if (cnt == n / 2) {

		vector<int>start, link;
		for (int i = 0; i < n; i++) {
			if (used[i] == true) start.push_back(i);
			else link.push_back(i);
		}
		int sstat = 0, lstat = 0;
		for (int i = 0; i < start.size(); i++) {
			for (int j = i + 1; j < start.size(); j++) {
				sstat += stats[start[i]][start[j]] + stats[start[j]][start[i]];
				lstat += stats[link[i]][link[j]] + stats[link[j]][link[i]];
			}
		}
		cha = min(cha, abs(sstat - lstat));
		return;
	}
	for (int i = curr; i < n; i++) {//왜 i가 curr+1부터인지? 이것도 검색햇슴 이건 다시 설명듣고 다시짜봐야할듯
		if (used[i] == false) {	
			used[i] = true;
			backtracking(i+1, cnt + 1);
			used[i] = false;
		}
	}
	return;
}
int main() {

	cin >> n;
	stats.resize(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a; cin >> a;
			stats[i][j] = a;
		}
	}

	backtracking(0,0);
	cout << cha;
}