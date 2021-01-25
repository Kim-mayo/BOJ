#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
using namespace std;
string maze[100];
bool visited[100][100];
queue<pair<int,int > > Q;
int N, M;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int BFS(int x, int y) {
	int cnt = 1;
	Q.push({ x,y });
	
	int nx = 0, ny = 0;
	while (!Q.empty()) {

		int qsize = Q.size();
		for (int p = 0; p < qsize; p++) {
			pair<int, int> fr = Q.front();

			Q.pop();
			if (fr.first == N - 1 && fr.second == M - 1) return cnt;
			if (visited[fr.first][fr.second] == true) continue;
			visited[fr.first][fr.second] = true;

			for (int i = 0; i < 4; i++) {
				nx = fr.first + dx[i];
				ny = fr.second + dy[i];

				if (0 <= nx && nx < N && 0 <= ny && ny < M) {
					if (maze[nx][ny] == '1' && visited[nx][ny] == false) {
						Q.push({ nx,ny });
					}
				}
			}
		}
		cnt++;
	}
	return -1;
}
int main() {

	 cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> maze[i];
	}


	
				
			

	cout << BFS(0, 0);

}