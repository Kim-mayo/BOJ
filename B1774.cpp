#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

#define INF 1e9
int n, m;
priority_queue<pair<int,pair<int, int>>>pq;//cost,x,y
vector<pair<int,int>>link;
vector<int>parent;
vector<pair<double,pair<int, int>>>linked;
int find(int v) {
	if (parent[v] == v)return v;
	else return parent[v] = find(parent[v]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return true;
	parent[a] = b;
	return false;
}
double Kruskal() {

	double scost = 0;
	for (int i = 0; i < linked.size(); i++) {
		int a = linked[i].second.first;
		int b = linked[i].second.second;
		double cost = linked[i].first;
		if (merge(a, b))continue;
		scost += cost;
	}
	return scost;
}
void input() {

	cin >> n >> m;
	parent.resize(n + 1);
	for (int i = 1; i <= n; i++)parent[i] = i;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		link.push_back({ a,b });
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++){
			double cost = sqrt(pow(link[i].first - link[j].first, 2) + pow(link[i].second - link[j].second, 2));
			linked.push_back({ cost,{i,j} });
		} 
	}
	sort(linked.begin(), linked.end());

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		merge(a - 1, b - 1);
	}
	
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	cout << fixed;
	cout.precision(2);
	cout << Kruskal();
}