#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n, k; cin >> n >> k;
	vector<int>change;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		change.push_back(a);
	}
	int cnt = 0;
	for (int i = change.size()-1; i >=0; i--) {
		if (k == 0)break;
		if (k / change[i] == 0)continue;
		int coin = k / change[i];
		cnt += coin;
		k = k - (change[i] * coin);
	}
	cout << cnt;

}