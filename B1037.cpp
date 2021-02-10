#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long>arr;
int main() {

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		long long a; cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	long long mul = arr.front() * arr.back();
	cout << mul;

}