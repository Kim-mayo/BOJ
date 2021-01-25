#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>chu;
int main() {

	int N; cin >> N;
	chu.resize(N);
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		chu[i] = a;
	}
	sort(chu.begin(), chu.end());


	if (chu[0] != 1) {
		cout << "1";
		return 0;
	}

	int chusum = 1;
	for (int i = 1; i < N; i++) {
		if (chusum + 1 >= chu[i]) chusum += chu[i];
		else {
			cout << chusum + 1;
			return 0;
		}
	}
	cout << chusum + 1;
}