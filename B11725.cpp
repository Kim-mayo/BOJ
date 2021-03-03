#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define INF 1e9
vector<vector<int>>tree;
vector<int>visited;//parent넣을거ㅇ야
queue<pair<int, int>>q;
void Dfs(int child) {

	if (child == 1)visited[child] = 0;

	for (int i = 0; i < tree[child].size(); i++) {
		int childc = tree[child][i];
		if (visited[childc] != INF)continue;
		visited[childc] = child;
		Dfs(childc);
	}
	return;
}
void Bfs() {

	visited.resize(tree.size(),INF);
	q.push({ 0,1 });
	visited[1] = 1;
	while (!q.empty()) {

		int parent = q.front().first;
		int child = q.front().second;
		q.pop();
		for (int i = 0; i < tree[child].size(); i++) {
			int childc = tree[child][i];
			if (visited[childc] != INF)continue;
			q.push({ child,childc });
			visited[childc] = child;
		}


	}

}
void input() {

	int n; cin >> n;
	tree.resize(n + 1);
	for (int i = 0; i < n-1; i++) {

		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);

	}

}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	//Bfs();
	visited.resize(tree.size(),INF);
	Dfs(1);
	for (int i = 2; i < visited.size(); i++) {
		cout << visited[i] << "\n";
	}

}