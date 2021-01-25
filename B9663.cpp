#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int result;
vector<pair<int, int>>pos;

bool Queen_check(int x,int y) {

	for (int i = 0; i < pos.size(); i++) {
		if (pos[i].second == y) return false;
		if (abs(pos[i].first - x) == abs(pos[i].second - y)) return false;
	}
	return true;
}
void N_Queen(int row) {

	if (row == n) {
		result += 1;
		return;
	}

	for (int col = 0; col < n; col++) {
		if (Queen_check(row,col)) {
			pos.push_back({ row,col });
			
			N_Queen(row+1);
			pos.pop_back();
		}
	}

}
int main() {

	cin >> n;
	N_Queen(0);

	cout << result;
}