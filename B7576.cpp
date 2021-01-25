#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector < vector < int > >box;
vector < vector < bool > >visited;
int M, N;
queue < pair <int,int> >Q;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };

int BFS(int x, int y) {

	Q.push({ x,y });
	int nx, ny;
	while () {



	}

}
int main() {

	//bfs하구 모두1이되면 몇번만에됬는지출력,
	
	cin >> M >> N;

	box.resize(N, vector<int>(M,0));
	visited.resize(N, vector<bool>(M, false));
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
		}
	}



}