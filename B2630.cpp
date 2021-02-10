#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>paper;
int dx[4] = { 0,0,1,1 }, int dy[4] = { 0,1,0,1 };
pair<int,int> color_division(int row,int col,int n) {

	if (n == 1) {
		if (paper[row][col] == 0) return { 1,0 };//{È­ÀÌÆ®°¹¼ö,ºí·ç°¹¼ö}
		else return { 0,1 };
	}

	int white = 0, blue = 0;
	for (int i = 0; i < 4; i++) {
		auto it = color_division(row + dx[i] * n / 2, col + dy[i] * n / 2, n / 2);
		white += it.first;
		blue += it.second;
	}
	if (white == 0) return { 0,1 };
	else if (blue == 0) return { 1,0 };
	else {
		return { white, blue };
	}

}
int main() {

	int n; cin >> n;
	paper.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a; cin >> a;
			paper[i].push_back(a);
		}
	}
	
	auto it = color_division(0, 0, n);
	cout << it.first << "\n" << it.second;
}