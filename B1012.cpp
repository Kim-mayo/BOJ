#include <iostream>
#include <vector>
using namespace std;

vector < vector < int > >bat(50,vector<int>(50,0));
bool visited[50][50];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };

void DFS(int x, int y,int M,int N,int worm) {
	if (visited[x][y] == true)return;
	visited[x][y] = true;
	
	int nx = 0, ny = 0;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (0 <= nx && nx < M && 0 <= ny && ny < N) {
			if (bat[nx][ny] == 1 && visited[nx][ny] == false){
				DFS(nx, ny, M, N, worm);
			}
		}
	}

	return;
}

int main() {

	
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		int M, N, K; 
		
		
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			int x = 0, y = 0;
			cin >> x >> y;
			bat[x][y] = 1;
		}
		int worm = 1;
		for (int k = 0; k < M; k++) {
			for (int q = 0; q < N; q++) {

				if (bat[k][q]==1&&visited[k][q] == false){
					DFS(k, q, M, N, worm);
					worm++;
				}
			}
		}
		cout << worm-1 << "\n";
		for (int k = 0; k < M; k++) {
			for (int q = 0; q < N; q++) {
				visited[k][q] = false;
				bat[k][q] = 0;
			}
		}
	}

	

}