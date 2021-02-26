#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9
vector < vector<pair<int, int>>>road;
priority_queue<pair<int, int>>pq;
int dist[1001];
int count[1001];
int k;
void Daijkstra() {
	for (int i = 1; i <= road.size(); i++) {
		for (int j = 0; j <= road.size(); j++) {
			dist[i][j] = INF;
		}
	}

	pq.push({ 0,1 });
	while (!pq.empty()) {

		int time = pq.top().first;
		int city = pq.top().second;
		pq.pop();
		if (count[city] == k)continue;
		dist[city] = -time;
		
		for (int i = 0; i < road[city].size(); i++) {

			int ncity = road[city][i].first;
			int ntime = road[city][i].second;
			if (dist[ncity][k] != INF)continue;
			else {
				pq.push({ time - ntime,ncity });
				
			}

		}

	}

}
void input() {

	int n, m; cin >> n >> m >> k;
	road.resize(n+1);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		road[a].push_back({ b,c });//[출발도시][i] = 도착도시,시간
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	input();
	
}