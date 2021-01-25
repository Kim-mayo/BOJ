#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>>matrix;
int main() {

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		matrix.push_back({ x,y });
	}
	sort(matrix.begin(), matrix.end());

	for (int i = 0; i < n; i++) {
		cout << matrix[i].first << " " << matrix[i].second << "\n";
	}
}