#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9
vector<vector<int>>cave;
int dist[126][126];
int n;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int Daijkstra() {

	priority_queue < pair<int, pair<int, int>>>pq;
	for (int i = 0; i < 126; i++) {
		for (int j = 0; j < 126; j++) {
			dist[i][j] = INF;
		}
	}
	pq.push({-cave[0][0],{0,0} });
	while (!pq.empty()) {

		auto curr = pq.top();
		int x = curr.second.first;
		int y = curr.second.second;
		int cost = curr.first;
		pq.pop();
		if (dist[x][y] != INF)continue;
		dist[x][y] = -cost;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (dist[nx][ny] <cave[nx][ny]-cost)continue;
				else if (dist[nx][ny] != INF) { dist[nx][ny] = cave[nx][ny] - cost; continue; }
				pq.push({ cost - cave[nx][ny],{nx,ny} });
			}
		}

	}
	return dist[n - 1][n - 1];

}
bool input() {

	cin >> n;
	if (n == 0)return false;
	cave.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a; cin >> a;
			cave[i].push_back(a);	
		}
	}

}
int main() {

	ios_base::sync_with_stdio(false);
	int tc = 1;
	while (1) {

		if (!input())return 0;
		cout << "Problem " <<  tc << ": ";
		int ans = Daijkstra();
		cout << ans << "\n";
		cave.clear();
		tc++;
	}
}