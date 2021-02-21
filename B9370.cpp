#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 1e9
int s, g, h;
vector<vector<pair<int, int>>>adj;
int can[101];
int vertex_n, can_n, edge_n; 

void Daijk(int s,vector<int>&dist){//size -> vertex_n

	priority_queue<pair<int, int>>pq;

	pq.push({ 0,s });
	while (!pq.empty()) {

		auto top = pq.top();
		int dis = top.first;
		int curr_v = top.second;
		pq.pop();

		if (dist[curr_v] != INF)continue;
		dist[curr_v] = -dis;
		for (int i = 0; i < adj[curr_v].size(); i++) {

			int next_v = adj[curr_v][i].second;
			int next_d = adj[curr_v][i].first;

			if (dist[next_v] != INF)continue;
			pq.push({ dis - next_d,next_v });

		}
	}

}
void input() {

	cin >> vertex_n >> edge_n >> can_n;
	adj.resize(vertex_n + 1);
	cin >> s >> g >> h;
	for (int i = 0; i < edge_n; i++) {

		int a, b, c; cin >> a >> b >> c;
		if ((a == g && b == h) || (a == h && b == g)) {
			adj[0].push_back({ c,0 });
		}
		adj[a].push_back({ c,b });//거리,연결된 정점
		adj[b].push_back({ c,a });

	}
	
	for (int i = 0; i < can_n; i++) {
		int a; cin >> a;// 목적지 후보 ~~~
		can[i] = a;
	}
	sort(can + 0, can + can_n);
}
void solution() {

	int t; cin >> t;
	for (int i = 0; i < t; i++) {

		input();
		vector<int>dist_1(vertex_n+1, INF);
		vector<int>dist_2(vertex_n+1, INF);
		vector<int>dist_3(vertex_n + 1, INF);
		Daijk(s,dist_1);
		Daijk(g, dist_2);
		Daijk(h, dist_3);
		int a[101], b[101];
		for (int j = 0; j < can_n; j++) {
			a[can[j]] = dist_1[can[j]];

			if (dist_1[g] > dist_1[h]) {
				b[can[j]] = dist_1[h] + dist_2[can[j]];
			}
			else if (dist_1[h] > dist_1[g]) {
				b[can[j]] = dist_1[g] + dist_3[can[j]];
			}
			else {
				b[can[j]] = min(dist_1[g] + dist_2[can[j]], dist_1[h] + dist_3[can[j]]);
				
			}

			if (a[can[j]] >= b[can[j]]+adj[0][0].first) {
				cout << can[j] << " ";
			}
		}
		dist_1.clear();
		dist_2.clear();
		adj.clear();
		for (int k = 0; k < 101; k++)can[k] = 0;
		cout << "\n";
	}

}
int main() {


	solution();

}