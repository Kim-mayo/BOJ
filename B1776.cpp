#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<vector<int>>problem;
vector<int>inq;
priority_queue<int>pq;
void topology_sort() {

	for (int i = 1; i <= n; i++) {
		if (inq[i] == 0) {
			pq.push(-i);
		}
	}
	
	while (!pq.empty()) {
		int fr = -pq.top();
		pq.pop();
		cout << fr << " ";

		for (int i = 0; i < problem[fr].size(); i++) {
			inq[problem[fr][i]]--;
			if (inq[problem[fr][i]] == 0) pq.push(-problem[fr][i]);
		}

	}
	
}
int main() {

	cin >> n >> m;
	problem.resize(n+1);
	inq.resize(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		problem[a].push_back(b);
		inq[b]++;
	}


	topology_sort();


}