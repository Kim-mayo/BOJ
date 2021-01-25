#include <iostream>
using namespace std;

int Fact(int n) {

	if (n == 0) return 1;
	if (n == 1) return 1;

	return n * Fact(n - 1);
}
int main() {

	int N; cin >> N;
	cout << Fact(N);
}