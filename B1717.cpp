#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define INF 1e9
vector<int>parent;
int find(int v) {

	if (v == parent[v])return v;
	else return parent[v] = find(parent[v]);

}
void merge(int a, int b) {

	int A = find(a);
	int B = find(b);
	parent[A] = B;

}
void input() {
	int n, m; cin >> n >> m;
	parent.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			if (find(b) == find(c))cout << "YES\n";
			else cout << "NO\n";
		}
		else if (a == 0) {
			merge(b, c);
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();

}