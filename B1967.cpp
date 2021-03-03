#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define INF 1e9

vector<vector<pair<int, int>>>edge;
vector<int>visited;
int Daijkstra(int s) {

	visited.resize(edge.size(), INF);
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,s });

	while (!pq.empty()) {

		int dis = pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		if (visited[curr] != INF)continue;
		visited[curr] = dis;
		for (int i = 0; i < edge[curr].size(); i++) {
			int next = edge[curr][i].first;
			int ndid = edge[curr][i].second;
			if (visited[next] != INF)continue;
			pq.push({ ndid + dis,next });
		}

	}
	int index = 0;
	int far = -INF;
	for (int i = 1; i < visited.size(); i++) {
		if (far < visited[i]) {
			far = visited[i];
			index = i;
		}
	}
	return index;
}
void input() {

	int n; cin >> n;
	edge.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	int i =Daijkstra(1);
	visited.clear();
	int index = Daijkstra(i);
	cout << visited[index];
}