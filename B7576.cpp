#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n;
vector<vector<int>>box;
queue<pair<int,int>>q;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int day;
void tomato() {
		
	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {
			int curr_row = q.front().first;
			int curr_col = q.front().second;
			q.pop();
			int nextrow = 0, nextcol = 0;
			for (int i = 0; i < 4; i++) {
				nextrow = curr_row + dx[i];
				nextcol = curr_col + dy[i];
				if (0 > nextrow || nextrow >= n || 0 > nextcol || nextcol >= m || box[nextrow][nextcol] != 0)continue;//범위오바쌈바디바!
				q.push({ nextrow,nextcol });
				box[nextrow][nextcol] = 1;
			}
		}
		day++;
	}
	return;
}
int main() {

	cin >> m >> n;
	box.resize(n, vector<int>(m));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
			box[i][j] = a;
			if (a == 1) {
				q.push({ i,j });
			}
		}
	}
	tomato();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] ==0) {
				cout << "-1";
				return 0;
			}
			
		}
	}
	cout << day-1;

}