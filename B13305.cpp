#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e10
#define ll long long
int main() {

	int n; cin >> n;
	vector<ll>dis;
	for (int i = 0; i < n - 1; i++) {
		ll a; cin >> a;
		dis.push_back(a);
	}
	ll oil = 0;
	ll me = INF;
	for (int i = 0; i < n-1; i++) {
		ll a; cin >> a;
		if (a < me) {
			me = a;
			oil += me * dis[i];
		}
		else {
			oil += me * dis[i];
		}
	}
	ll a; cin >> a;
	cout << oil;
}