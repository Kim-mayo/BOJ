#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define m 1000000007
ll a, b;
void input() {
	cin >> a >> b;
}
ll fact(ll s,ll e) {
	ll ret = 1;
	for (int i = s; i <= e; i++) {
		ret = ret * i % m;
	}
	return ret;
}
ll pow_(ll n, ll k) {

	if (k == 1) return n;

	ll ret = pow_(n, k / 2) % m;
	ret = (ret * ret) % m;
	if (k % 2 == 1)ret = (ret * n) % m;
	return ret;

}
int main() {

	input();
	b = min(b, a - b);
	ll p = fact(a-b+1,a);
	ll q = fact(1,b);
	
	cout << (p % m * (pow_(q, m - 2)) % m) % m;
}