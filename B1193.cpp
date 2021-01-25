#include <iostream>
using namespace std;

int main() {

	int N; cin >> N;

	int i = 1;
	int sum = 0;
	int num = 0;
	if (N == 1) { cout << "1/1"; return 0; }
	for (i = 1; sum+i < N; i++) {
		sum += i;
		num = N - sum;
	}
	if (i % 2 == 1) cout << i - num + 1 << "/" << num;
	else cout << num << "/" << i + 1 - num;
}
