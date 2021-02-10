#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long 
int divide5(int a, int b) {
	ll c = a - b;
	ll suma = 0, sumb = 0, sumc = 0;
	while (1) {
		if (a == 0)break;
		suma += a / 5;
		a /= 5;
	}
	while (1) {
		if (b == 0)break;
		sumb += b / 5;
		b /= 5;
	}

	while (1) {
		if (c == 0) break;
		sumc += c / 5;
		c /= 5;
	}

	return suma - (sumb + sumc);
}
int divide2(int a, int b) {
	ll c = a - b;
	ll suma = 0, sumb = 0, sumc = 0;
	while (1) {
		if (a == 0)break;
		suma += a / 2;
		a /= 2;
	}
	while (1) {
		if (b == 0)break;
		sumb += b / 2;
		b /= 2;
	}

	while (1) {
		if (c == 0) break;
		sumc += c / 2;
		c /= 2;
	}

	return suma - (sumb + sumc);
}
int main() {

	ll a, b; cin >> a >> b;
	
	cout << min(divide2(a, b), divide5(a, b));
	
}