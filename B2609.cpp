#include <iostream>
using namespace std;

int gcf(int a, int b) {
	return b ? gcf(b, a % b) : a;
}
int main() {

	int a, b; cin >> a >> b;

	int f = gcf(a, b);
	int m = (a * b) / f;

	cout << f << "\n" << m;

}