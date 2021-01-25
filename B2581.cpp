#include <iostream>
#include <queue>
using namespace std;

int m, n;
priority_queue<int>pq;
int prime_fine(int m, int n) {

	for (int i = m; i <= n; i++) {
		if (i == 1) continue;
		bool pre = false;
		for (int j = 2; j < i / 2 + 1; j++) {
			if (i % j == 0) pre = true;
		}
		if (!pre) pq.push(-i);
	}
	if (pq.empty()) return -1;

	int min = pq.top();
	return -min;
}
int prime_sum() {

	int sum = 0;
	
	while (!pq.empty()) {
		int fr = pq.top();
		pq.pop();
		sum += fr;
	}

	return -sum;
}
int main() {

	cin >> m >> n;
	int MIN = prime_fine(m, n);
	int SUM = prime_sum();
	if (MIN == -1) {
		cout << MIN;
		return 0;
	}
	cout << SUM << "\n" << MIN;
	
	return 0;
}