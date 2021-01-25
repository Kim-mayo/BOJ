#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>check(10001,0);
int main() {

	ios_base::sync_with_stdio(false);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {

		int a; cin >> a;
		check[a]++;

	}


	for (int i = 0; i < check.size(); i++) {
		if (check[i] != 0) {
			for (int j = 0; j < check[i]; j++) {
				cout << i << "\n";
			}
		}
	}
}