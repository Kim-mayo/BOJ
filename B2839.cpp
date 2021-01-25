#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e9
int Sugar_boy(int N) {

	int five = 0;
	int three = 0;
	int bag = INF;
	for (three; three*3 <= N; three++) {
		if ((N - three * 3) % 5 == 0) {
			five = (N - three * 3) / 5;
			bag = min(bag, three + five);
		}
	}
	if (bag == INF) {
		return -1;
	}
	return bag;
}
int main() {
	int N; cin >> N;

	cout << Sugar_boy(N);
}