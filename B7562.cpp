#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int dx[8] = { -1, -2,-2,-1,1,2,2,1 };
int dy[8] = { 2,   1,-1,-2,2,1,-1,-2 };

int BFS(int r, int c,int n, int eer, int eec) {
	vector<vector<int>>visited;
	visited.resize(n, vector<int>(n, 0));
	int day = 1;
	queue<pair<int, int>>q;
	q.push({ r, c });
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {

			auto fr = q.front();
			int cr = fr.first;
			int cc = fr.second;
			q.pop();
			if (cr == eer && cc == eec)return day-1;
			if (visited[cr][cc] != 0)continue;
			visited[cr][cc] = day;
			for (int i = 0; i < 8; i++) {
				int nx = cr + dx[i];
				int ny = cc + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (visited[nx][ny] != 0)continue;
					
					q.push({ nx,ny });
				}
			}

		}
		day++;
	}


}
int main() {

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		int sr, sc; cin >> sr >> sc;
		int er, ec; cin >> er >> ec;
		cout << BFS(sr, sc, n, er, ec) << "\n";
		
	}

}