#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

priority_queue<pair<int, int>>pq;
int main() {

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (num == 0) {
			if (pq.empty()) {
				cout << "0\n"; continue;
			}
			int top = -pq.top().second;
			pq.pop();
			cout << top; continue;
		}
		pq.push({ -abs(num),-num });
		
	}
}