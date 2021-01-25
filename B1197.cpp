#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector<int> parent(100001);
vector <pair <int,pair <int, int>> >sorted;
vector <int> Rank(100001);
int find(int v) {
	if (parent[v] == v)return v;
	return parent[v] = find(parent[v]);
}

int cnt[100001];
void merge(int u, int v) {
	
	u = find(u);
	v = find(v);

	if (Rank[u] > Rank[v]) {
		parent[v] = u;
		cnt[u] += cnt[v];
	}
	else if (Rank[u] < Rank[v]) {
		parent[u] = v;
		cnt[v] += cnt[u];

	}
	else {
		Rank[u]++;
		parent[v] = u;
		cnt[u] += cnt[v];

	}


}

int main() {

	ios_base::sync_with_stdio(false);
	
	int v, e; cin >> v >> e;
	for (int i = 0; i < v; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;

		sorted.push_back({ c,{a,b} });
	}
	sort(sorted.begin(), sorted.end());
	int weight = 0;
	int multi_w = 0;
	for (int i = 0; i < e; i++) {
		int weight = 0;
		int a = sorted[i].second.first;
		int b = sorted[i].second.second;
		int c = sorted[i].first;
		if (find(a) != find(b)) {
			merge(a, b);
			weight = c;
			multi_w += weight;
		}
		else if (find(a) == find(b)) {
			continue;
		}
	}
	cout << multi_w;
}