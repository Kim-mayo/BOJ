#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int from, int to) {

	if (n == 0) return;

	hanoi(n - 1, from, 6 - from - to);
	cout << from << " " << to << "\n";
	hanoi(n - 1, 6 - from - to, to);

	return;

}
int main() {

	int n; cin >> n;
	cout << int(pow(2, n))-1 << "\n";
	hanoi(n,1,3);

}