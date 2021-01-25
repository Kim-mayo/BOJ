#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector < vector<int> >graph;
vector <bool> visited;

void DFS(int Vertex) {

	if (visited[Vertex] == true)return;
	visited[Vertex] = true;
	cout << Vertex+1 << " ";
	for (int i = 0; i < graph[Vertex].size(); i++) {
		int next_vertex = graph[Vertex][i];
		if (visited[next_vertex] == true) continue;
		
		DFS(next_vertex);
	}

	return;
}

void BFS(int Vertex) {

	queue <int> Q;
	Q.push(Vertex);

	while (!Q.empty()) {

		int front = Q.front();
		Q.pop();

		if (visited[front] == true) continue;
		visited[front] = true;
		cout << front+1 << " ";

		for (int i = 0; i < graph[front].size(); i++) {

			int next_vertex = graph[front][i];
			if (visited[next_vertex] == true) continue;
			Q.push(next_vertex);

		}

	}
	return ;

}


int main() {

	int vertex_num, edge_num,Vertex;
	cin >> vertex_num >> edge_num >> Vertex;
	Vertex--;
	graph.resize(vertex_num);
	visited.resize(vertex_num, false);

	for (int i = 0; i < edge_num; i++) {

		int u, v; cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);

	}

	for (int i = 0; i < vertex_num; i++) {

		sort(graph[i].begin(), graph[i].end());

	}

	DFS(Vertex);
	cout << "\n";
	visited.clear();
	visited.resize(vertex_num,false);
	BFS(Vertex);

}