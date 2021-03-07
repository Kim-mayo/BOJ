#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define INF 1e9
vector<vector<int>>graph;
vector<int>visited;
bool Bfs(int curr) {

	queue<int>q;
	q.push(curr);
	int vn = 0, edge = 0;
	while (!q.empty()) {

		int vertex = q.front();
		q.pop();
		vn++;
		for (int i = 0; i < graph[vertex].size(); i++) {
			int nextv = graph[vertex][i];
			if (visited[nextv] != -1)continue;
			q.push(nextv);
		}
		visited[vertex] = graph[vertex].size();
		edge += visited[vertex];
	}

	if (edge / 2 == vn - 1)return true;
	else return false;
}
bool Dfs(int prev, int curr) {

	visited[curr] = true;
	bool ok = true;
	for (int i = 0; i < graph[curr].size(); i++) {

		int nextv = graph[curr][i];
		if (nextv == prev)continue;
		if (visited[nextv] == true) ok = false;
		
		Dfs(curr, nextv);

	}
	return ok;
}
void input() {
	int k = 1;
	while (1) {

		int n, m; cin >> n >> m;
		if (n == 0 && m == 0)return;
		graph.resize(n + 1);
		visited.resize(n + 1,-1);
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (visited[i] !=-1)continue;
			if (Bfs(i)) cnt++;			
		}
		cout << "Case " << k << ": ";
		if (cnt == 0) {
			cout << "No trees.\n";
		}
		else if (cnt == 1) {
			cout << "There is one tree.\n";
		}
		else {
			cout << "A forest of " << cnt << " trees.\n";
		}
		//초기화해주기
		graph.clear();
		visited.clear();
		k++;
	}

}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();

}