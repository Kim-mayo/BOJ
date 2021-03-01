#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define INF 1e9


void input() {

	int n; cin >> n;
	for (int i = 0; i < n; i++) {

		long long a, b; cin >> a >> b;
		cout << (a + b) * (a + b - 1) * (a + b) / 2 << "\n";

	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();

}