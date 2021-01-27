	#include <iostream>
	#include <vector>
	#include <queue>
	using namespace std;

	vector<vector<int>>com;
	queue<int>q;
	bool visited[101];
	void Virus(int infec) {
		q.push(infec);

		while (!q.empty()) {

			int inf = q.front();
			q.pop();
			visited[inf] = true;
			for (int i = 0; i < com[inf].size(); i++) {
				if (visited[com[inf][i]] == true)continue;
				if (visited[com[inf][i]] == false) {
					q.push(com[inf][i]);
					//visited[com[inf][i]] = true;
				}
			}

		}

	}
	int main() {

		int n; cin >> n;
		com.resize(n+1);
		int link; cin >> link;
		for (int i = 0; i < link; i++) {
			int a, b; cin >> a >> b;
			com[a].push_back(b);
			com[b].push_back(a);
		}
		Virus(1);
		int worm=0;
		for (int i = 2; i <= n; i++) {
			if (visited[i] == true)worm++;
		}
		cout << worm;
	}