#include <iostream>
#include <queue>
using namespace std;

priority_queue<int>pq;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int cal; cin >> cal;
		if (cal == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				int big = pq.top();
				pq.pop(); 
				cout << big << "\n";
			}
		}
		else pq.push(cal);
	}

}