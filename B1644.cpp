#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define INF 1e9
#define ll long long
vector<ll>prime;
vector<bool>check;
void Eratos(ll num) {
	check.resize(num+1,true);

	for (ll i = 2; i <= num; i++) {
		if (check[i] != true)continue;
		prime.push_back(i);
		for (ll j = i * i; j <= num; j += i) {
			check[j] = false;
		}
	}

}
ll Solution(ll num) {

	int i = 0;
	int j = 0;
	ll sum = 0;
	ll cnt = 0;
	int n = prime.size();
	while (j < n) {

		if (sum < num) {
			sum += prime[j];
			j++;
		}
		else if (sum  > num) {
			sum -= prime[i];
			i++;
		}
		else if (sum == num) {
			cnt++;	
			sum += prime[j];
			sum -= prime[i];
			i++;
			j++;
		}

	}
	while (i < n) {
		if (sum > num) {
			sum -= prime[i];
			i++;
		}
		else if (sum == num) {
			cnt++;
			sum -= prime[i];
			i++;
		}
		else if(sum<num) {
			break;
		}
	}
	return cnt;
}
int main() {	

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n; cin >> n;
	Eratos(n);
	cout << Solution(n);

}