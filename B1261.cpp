#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>>maze;
int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int Bfs(int sr,int sc) {

	//최소비용,x,y
	priority_queue<pair<int, pair<int, int>>>pq;
	vector<vector<int>>visited;
	visited.resize(maze.size(), vector<int>(maze[0].size(), -1));
	pq.push({ 0,{sr,sc} });

	while (!pq.empty()) {

		int cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (visited[x][y] != -1)continue;
		visited[x][y] = -cost;
		for (int i = 0; i < 4; i++) {
			
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (visited[nx][ny] != -1)continue;
				pq.push({ cost - maze[nx][ny],{nx,ny} });
			}

		}

	}
	return visited[n-1][m-1];
}
void input() {

	cin >> m >> n;
	maze.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char a; cin >> a;
			maze[i].push_back(a-'0');
		}
	}

}
int main() {

	input();

	cout << Bfs(0,0);

}