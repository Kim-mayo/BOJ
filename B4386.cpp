#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
vector < pair <double, double>> location;
vector <pair<double,pair<int,int>>>make_edge;
vector <int >parent;
vector <int>Rank;

int Find(int V) {
	if (parent[V] == V) return V;
	return parent[V] = Find(parent[V]);
}

void Merge(int u, int v) {
	u = Find(u);
	v = Find(v);

	if (Rank[u] > Rank[v]) {
		parent[v] = u;
	}
	else if (Rank[u] < Rank[v]) {
		parent[u] = v;
	}
	else {
		Rank[u]++;
		parent[v] = u;
	}
}

int main() {

	int n; cin >> n;
	parent.resize(n, 0);
	Rank.resize(n, 0);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		double x, y; cin >> x >> y;
		location.push_back({ x,y });
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double a = location[i].first;
			double b = location[i].second;
			double c = location[j].first;
			double d = location[j].second;
			double dis = sqrt(((a - c) * (a - c)) +((b - d)* (b - d))) ;
			make_edge.push_back({ dis,{i,j} });
		}
	}

	sort(make_edge.begin(), make_edge.end());
	double multi_w = 0;
	for (int i = 0; i < make_edge.size(); i++) {

		double weight = 0;
		int a = make_edge[i].second.first;
		int b = make_edge[i].second.second;
		double c = make_edge[i].first;
		if (Find(a) != Find(b)) {
			Merge(a, b);
			weight = c;
			multi_w += weight;
		}
		else continue;

	}
	cout << multi_w;
}