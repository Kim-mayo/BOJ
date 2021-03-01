#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define INF 1e9
vector<int>sq;
int n, s;
int two_pointer() {

	int sum = 0;
	int i = 0;
	int j = 0;
	int minlength = INF;
	while(j<n){

		if (sum < s) {
			sum += sq[j];
			j++;
		}
		else if (sum >= s) {
			sum -= sq[i];
			if (minlength > j - i) {
				minlength = j - i;
			}
			i++;
		}
	}

	while (i < n) {

		if (sum >= s) {
			sum -= sq[i];
			if (minlength > j - i) {
				minlength = j - i;
			}
			i++;
		}
		else break;
	}

	return minlength;
}
void input() {

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		sq.push_back(a);
	}

}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	int ans = two_pointer();
	if (ans != INF) {
		cout << ans;
		return 0;
	}
	else {
		cout << "0";
	}
}