#include <iostream>
using namespace std;

#define ll long long
ll a, b, c;
void input() {
	cin >> a >> b >> c;
}
ll Division(ll n, ll k) {

	if (k == 1) return n%c;

	ll num = 0;
	if (k % 2 == 0) {
		num = Division(n, k / 2) % c;
		num = (num * num) % c;
	}
	else {
		num = Division(n, k / 2)%c;
		num = (num * num) % c;
		num = (num * n) % c;
	}

	return num%c;

}
int main() {

	input();
	cout << Division(a, b)%c;

}