#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		queue <pair<int,int>> q;
			int n, m; cin >> n >> m;
			int cnt = 1;
			for (int k = 0; k < n; k++) {
				int pri; cin >> pri;
				q.push({ k,pri });
			}

			for (int k = 0; k < n; k++) {
				int qsize = q.size();
				int big = 0;
				for (int j = 0; j < qsize; j++) {
					auto fr = q.front();
					q.pop();
					q.push(fr);
					if (fr.second > big)big = fr.second;
				}
				for (int j = 0; j < qsize; j++) {
					auto fr = q.front();
					if (fr.second == big) break;
					else {
						q.pop();
						q.push(fr);
					}
				}

				if (q.front().first == m) break;
				else {
					cnt++;
					q.pop();
				}

			}
			cout << cnt << "\n";
	}

	

}