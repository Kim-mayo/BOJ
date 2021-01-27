#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>sdoku;
vector<pair<int, int>>pos;
void check(int row,int col,vector<bool>&used) {
	for (int i = 0; i < 9; i++) {
		used[sdoku[row][i]] = true;
	}
	for (int j = 0; j < 9; j++) {
		used[sdoku[j][col]] = true;
	}
	int sx = (row / 3) * 3;
	int sy = (col / 3) * 3;
	for (int i = sx; i < sx + 3; i++) {
		for (int j = sy; j < sy + 3; j++) {
			used[sdoku[i][j]] = true;
		}
	}
	return;
}
bool Sdoku(int curr) {
	
	if (curr == pos.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++){
				cout << sdoku[i][j] << " ";
			} 
			cout << "\n";
		}
		return true;
	}
	
	int row = pos[curr].first;
	int col = pos[curr].second;
	vector<bool>used(10, false);//used true => 차있는 수;
	check(row, col, used);
	for (int i = 1; i < 10; i++) {
		if (used[i] == true)continue;
		used[i] = true;
		sdoku[row][col] = i;
		if(Sdoku(curr + 1)==true) return true;
		used[i] = false;
		sdoku[row][col] = 0;
	}

	return false;
}
int main() {

	sdoku.resize(9, vector<int>(9));
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int a; cin >> a;
			sdoku[i][j] = a;
			if (a == 0) {
				pos.push_back({ i,j });
			}
		}
	}

	Sdoku(0);

}