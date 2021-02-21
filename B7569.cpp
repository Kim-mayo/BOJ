#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n, h;
queue<pair<int, pair<int, pair<int, int>>>>q;
int box[101][101][101];
bool visited[101][101][101];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
void input() {
	cin >> m >> n >> h;
	for(int k = 0;k < h; k++){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int a; cin >> a;
				box[i][j][k] = a;
				if (a == 1)q.push({ i,{j,{k,0}} });
			}
		}
	}
}
int BFS() {

	int result = 0;
	while (!q.empty()) {
		auto curr = q.front();
		int currx = curr.first;
		int curry = curr.second.first;
		int currz = curr.second.second.first;
		int currday = curr.second.second.second;
		result = max(result, currday);
		q.pop();
		if (visited[currx][curry][currz] == true)continue;
		visited[currx][curry][currz] = true;
		
		for (int i = 0; i < 6; i++) {//false이고, 박스안값이 0이고, 범위 체크-> 0<=currx+dx<n
			
			if (0 <= currx + dx[i] && currx + dx[i] < n && 0 <= curry + dy[i] && curry + dy[i] < m && 0 <= currz + dz[i] && currz + dz[i] < h) {
				if (visited[currx + dx[i]][curry + dy[i]][currz + dz[i]] != true && box[currx + dx[i]][curry + dy[i]][currz + dz[i]] == 0) {
					q.push({ currx + dx[i],{curry + dy[i],{currz + dz[i],currday + 1 }} });
					box[currx + dx[i]][curry + dy[i]][currz + dz[i]] = 1;
				}
			}
		}

	}
	return result;
}
int main() {

	input();
	int ret = BFS();
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (box[i][j][k] == 0) { ret = -1; break; }
			}
			if (ret == -1)break;
		}
		if (ret == -1)break;
	}
	cout << ret;
}