#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n; cin >> n;
	vector<int>num;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		num.push_back(a);
	}
	sort(num.begin(), num.end());
	int sum = 0;
	for (int i = 0; i < num.size(); i++) {
		sum += num[i];
		num[i] = sum;
	}
	int cnt = 0;
	for (int i = 0; i < num.size(); i++) {
		cnt += num[i];
	}
	cout << cnt;
	
}