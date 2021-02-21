#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue<pair<int, pair<int, int>>>q;
int arr[1001][1001];
int visited[1001][1001][2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m;
void input() {

	 cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char a; cin >> a;
			arr[i][j] = a-'0';
		}
	}

}

void BFS(int r,int c, int w) {
	q.push({ r,{c, w} });
	visited[r][c][w] = 1;

	while (!q.empty()) {

		auto fr = q.front();
		int r = fr.first;
		int c = fr.second.first;
		int w = fr.second.second;

		q.pop();
		
		for (int i = 0; i < 4; i++) {//범위,벽어케부시지?
			int nx = r + dx[i];
			int ny = c + dy[i];
			if (0 <=nx&& nx < n && 0 <=ny &&ny < m) {
				int nw = w + arr[nx][ny];
				if (nw >= 2)continue;
				if (visited[nx][ny][nw] != 0)continue;
				q.push({ nx,{ny,nw} });
				visited[nx][ny][nw] = 1 + visited[r][c][w];
			}

		}
		
	}
	

}
int main() {

	input();
	BFS(0, 0, 0);
	int a = visited[n - 1][m - 1][0];
	int b = visited[n - 1][m - 1][1];
	if (a == 0 && b == 0) {
		cout << "-1";
		return 0;
	}
	if (a == 0) a = 987654321;
	if (b == 0) b = 987654321;
	cout << min(a, b);
}