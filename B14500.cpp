#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>>p;
vector<vector<bool>>visited;
int dx[4] = { 0,-1,1,0 };
int dy[4] = { 1,0,0,-1 };

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	p.resize(n);
	visited.resize(n,vector<bool>(m,false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
			p[i].push_back(a);
		}
	}
}
int result = 0;
void DFS(int row, int col, int size,int sum) {

	if (size == 4) {
		result = max(sum, result);
		return;
	}

	int ret = p[row][col];
	visited[row][col] = true;
	for (int i = 0; i < 4; i++) {
		if (row + dx[i] == -1 || row + dx[i] == n || col + dy[i] == -1 || col + dy[i] == m)continue;
		if (visited[row + dx[i]][col+dy[i]] == true)continue;
		
		DFS(row + dx[i], col + dy[i], size + 1, ret + sum);
		
	}
	visited[row][col] = false;
	return;
}
void middle(int row, int col) {
	int sum11 = 0;
	if (row + 1 < n && 0 <= col - 1 && col + 1 < m) {
		int sum1 = p[row][col] + p[row + 1][col] + p[row + 1][col - 1] + p[row + 1][col + 1];
		int sum2 = p[row][col] + p[row][col - 1] + p[row][col + 1] + p[row + 1][col];
		sum11 = max(sum1, sum2);
	}
	int sum22 = 0;
	if (row - 1 >= 0 && row + 1 < n && col + 1 < m) {
		int sum1 = p[row][col] + p[row - 1][col] + p[row][col + 1] + p[row + 1][col];
		int sum2 = p[row][col] + p[row - 1][col + 1] + p[row][col + 1] + p[row + 1][col + 1];
		sum22 = max(sum1, sum2);
	}

	result = max(max(sum11, sum22), result);
	return;

}
int main() {

	input();
	int big = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			DFS(i, j, 0, 0);
			
			middle(i, j);
		}
	}
	
	cout << result;
}