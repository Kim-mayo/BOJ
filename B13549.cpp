#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9
int dist[100001];
priority_queue<pair<int, int>>pq;
int Bfs(int s, int e) {
	
	for (int i = 0; i < 100001; i++)dist[i] = INF;
	pq.push({ 0,s });
	while (!pq.empty()) {

		int time = pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		if (dist[curr] != INF)continue;
		dist[curr] = -time;
		if (curr == e)break;
		if (0<=(curr-1)&&dist[curr - 1] == INF) pq.push({ time - 1,curr - 1 });
		if (100001>(curr+1)&&dist[curr + 1] == INF) pq.push({ time - 1,curr + 1 });
		if ((curr*2)<100001&&dist[curr * 2] == INF) pq.push({ time,curr * 2 });

	}
	return dist[e];
}
int main() {

	ios_base::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	cout << Bfs(n, k);
	
}