	#include <iostream>
	#include <algorithm>
	#include <queue>
	#include <stack>
	#include <vector>
	#include <string>
	using namespace std;

	#define INF 1e9
	int n;
	vector<vector<pair<int, int>>>usado;
	vector<int>video;
	void recommend(int k,int v) {

		queue<pair<int, int>>q;
		vector<bool>visited(n + 1, false);
		q.push({ v,INF });
		visited[v] = true;
		while (!q.empty()) {

			int currv = q.front().first;
			int curru = q.front().second;
			q.pop();
	 
			for (int i = 0; i < usado[currv].size(); i++) {
				int nextv = usado[currv][i].first;
				int nextu = usado[currv][i].second;
				if (visited[nextv] == true)continue;
				if (min(nextu, curru) < k)continue;
				q.push({nextv,min(curru,nextu) });
				visited[nextv] = true;
				video.push_back(nextv);
			}
		}

	}
	void input() {

		int q; cin >> n >> q;
		usado.resize(n + 1);
		for (int i = 0; i < n - 1; i++) {
			int a, b, c; cin >> a >> b >> c;
			usado[a].push_back({ b,c });
			usado[b].push_back({ a,c });
		}
		for (int i = 0; i < q; i++) {
			int k, v; cin >> k >> v;//
			recommend(k, v);
			cout << video.size() << "\n";
			video.clear();
		}
	}
	int main() {

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		input();

	}