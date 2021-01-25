#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector < vector< pair<int,int>> > edge;
priority_queue < pair <int, pair<int, int>>> pq;
vector <bool>visited;

int main() {

	int v, e; cin >> v >> e;
	edge.resize(v + 1);
	visited.resize(v + 1, false);
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge[a].push_back({ b,-c });
		edge[b].push_back({ a,-c });
	}

	for (int i = 0; i < edge[1].size(); i++) {
		pq.push({ edge[1][i].second,{edge[1][i].first,1} });
	}
	visited[1] = true;
	int multi_w = 0;
	while (!pq.empty()) {

		pair <int, pair<int, int>> sel = pq.top();
		pq.pop();
		int cost = sel.first;
		int me = sel.second.second;
		int you = sel.second.first;
		if (visited[you] == false) {
			multi_w += cost;
			for (int i = 0; i < edge[you].size(); i++) {
				if (visited[edge[you][i].first] == true) continue;
				pq.push({ edge[you][i].second,{edge[you][i].first,you} });
			}
			visited[you] = true;
		}
		
	}

	cout << -multi_w;
}