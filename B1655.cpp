#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int>bq;
priority_queue<int>sq;
int main() {//nlogn

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	if (n == 1) { int a; cin >> a; cout << a; return 0; }
	int a, b; cin >> a >> b;
	cout << a << "\n";
	bq.push(min(a, b));
	sq.push(-max(a, b));
	cout << bq.top() << "\n";
	for (int i = 2; i < n; i++){

		int num; cin >> num;
		if (bq.top() <= num && num <= -sq.top()) {
			bq.push(num);
		}
		else if (bq.top() > num) {
			bq.push(num); 
		}
		else if (-sq.top() < num) {
			sq.push(-num); 
		}
		
		//사이즈비교
		if (bq.size() - sq.size() == 2) {
			int a = bq.top(); bq.pop(); sq.push(-a);
		}
		else if (sq.size() - bq.size() == 2) {
			int a = sq.top(); sq.pop(); bq.push(-a);
		}

		if (sq.size() == bq.size()) {
			cout << bq.top() << "\n";
		}
		else if (sq.size() - bq.size() == 1) {
			cout << -sq.top() << "\n";
		}
		else if (bq.size() - sq.size() == 1) {
			cout << bq.top() << "\n";
		}

		
	}
}