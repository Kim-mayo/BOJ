#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>>edge;
vector<int>visited;
void input() {

	int vertex_n, edge_n; cin >> vertex_n >> edge_n;
	edge.resize(vertex_n+1);
	visited.resize(vertex_n+1,0);
	for (int i = 0; i < edge_n; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
}
bool check_b(int s) {

	queue<int>q;
	q.push(s);
	visited[s] = 1;

	while (!q.empty()) {

		int curr = q.front();
		q.pop();

		for (int i = 0; i < edge[curr].size(); i++) {

			int nv = edge[curr][i];
			if (visited[nv] == visited[curr]) {
				return false;
			}
			else if (visited[nv] == 1 && visited[curr] == -1)continue;
			else if (visited[nv] == -1 && visited[curr] == 1)continue;
			//visited[nv] == 0ÀÌ¶ó¸é
			visited[nv] = visited[curr] * -1;
			q.push(nv);
		}

	}
	return true;
}
void solve() {

	int t; cin >> t;
	for (int i = 0; i < t ; i++) {
		input();
		int check = 0;
		for (int j = 1; j < visited.size(); j++) {
			if (visited[j] == 0) {
				if (check_b(j) == false) {
					check++;
					break;
				}
			}
		}
		if (check == 0)cout << "YES\n";
		else cout << "NO\n";

		visited.clear();
		edge.clear();
		//viisted clear, edge clear
	}


}
int main() {

	solve();

}