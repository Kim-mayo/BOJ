#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int>pq;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; cin >> N;
	
	for (int i = 0; i < N; i++) {
		int a;	cin >> a;
		
		if (a == 0) {
			if (pq.empty()) {
				cout << "0\n"; 
			}
			else {
				int top = -pq.top();
				pq.pop();
				cout << top << "\n";
			}
		}
		else {
			pq.push(-a);
		}
	
	}


}