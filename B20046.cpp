#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>>city;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int Bfs() {
	if (city[0][0] == -1 || city[n - 1][m - 1] == -1) return -1;
	priority_queue<pair<int, pair<int, int>>>pq;
	vector<vector<int>>visited;
	visited.resize(city.size(), vector<int>(city[0].size(), -100));
	
	pq.push({ -city[0][0],{0,0} });
	
	while (!pq.empty()) {

		int cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if (visited[x][y] != -100)continue;
		visited[x][y] = -cost;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m&&city[nx][ny]!=-1) {
				if (visited[nx][ny] != -100)continue;
				pq.push({ cost - city[nx][ny],{nx,ny} });
			}

		}

	}
	if (visited[n - 1][m - 1] == -100)return -1;
	else return visited[n - 1][m - 1];

}
void input() {

	cin >> n >> m;
	city.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
			city[i].push_back(a);
		}
	}

}
int main() {

	input();
	cout << Bfs();

}