#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define INF 1e9
vector<int>parent;
vector<int>plan;
int find(int v) {
	if (v == parent[v])return v;
	else return parent[v] = find(parent[v]);
}
void merge(int a, int b) {
	int A = find(a);
	int B = find(b);
	if (A == B)return;
	parent[A] = B;
}
void input() {

	int n, m; cin >> n >> m;
	parent.resize(n + 1);
	plan.resize(m + 1);

	for (int i = 1; i <= n; i++)parent[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a; cin >> a; 
			if (a == 1) {
				merge(i, j);
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		int a; cin >> a;
		plan[i] = a;
	}

}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	for (int i = 2; i < plan.size(); i++) {
		if (find(plan[i - 1]) != find(plan[i])) {
			cout << "NO"; return 0;
		}
	}
	cout << "YES";
}