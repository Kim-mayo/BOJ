#include <iostream>
using namespace std;

int Pivot(int n) {
	if (n == 1)return 1;
	if (n == 0)return 0;

	return Pivot(n - 1) + Pivot(n - 2);


}
int main() {

	int N; cin >> N;

	cout << Pivot(N);

}