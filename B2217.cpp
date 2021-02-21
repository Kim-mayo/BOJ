#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int n; cin >> n;
	vector<int>rope;
	
	for (int i = 0; i < n; i++) {

		int a; cin >> a;
		rope.push_back(a);

	}
	sort(rope.begin(), rope.end());
	int big = -1;
	for (int i = 0; i < n; i++) {
		big = max(big, rope[i] * (n - i));
	}
	cout << big;
}