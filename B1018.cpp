#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<char>>board;
vector<vector<char>>chess;
char FW[8][8];
char FB[8][8];
priority_queue<int>pq;
void Compare();
void Cut_arr() {

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			for (int k = 0; k < 8; k++) {
				for (int q = 0; q < 8; q++) {
					chess[k][q] = board[i+k][j+q];
				}
			}
			Compare();
		}
	}
	

}
void Compare() {
	int change_fw = 0;
	//FW랑 비교
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (FW[i][j] != chess[i][j]) {
				change_fw++;
			}
		}
	}
	int change_fb = 0;
	//FB랑 비교
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (FB[i][j] != chess[i][j]) {
				change_fb++;
			}
		}
	}

	//둘중 작은 거 pq에 넣기
	pq.push(-min(change_fw, change_fb));

}
int main() {

	cin >> n >> m;
	board.resize(n);
	chess.resize(8,vector<char>(8));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char a; cin >> a;
			board[i].push_back(a);
		}
	}
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				FW[i][j] = 'W';
				FB[i][j] = 'B';
			}
			else if (i % 2 == 0 && j % 2 != 0) {
				FW[i][j] = 'B';
				FB[i][j] = 'W';
			}
			else if (i % 2 != 0 && j % 2 == 0) {
				FW[i][j] = 'B';
				FB[i][j] = 'W';
			}
			else if (i % 2 != 0 && j % 2 != 0) {
				FW[i][j] = 'W';
				FB[i][j] = 'B';
			}
		}
	}
	
	Cut_arr();
	int change = -pq.top();
	cout << change;
}