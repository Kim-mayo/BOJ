#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int fre[8001];
vector<int>arr;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		sum += a;
		arr.push_back(a);
		fre[a+4000] += 1;
	}
	sort(arr.begin(), arr.end());

	long long avg = ((sum * 10) / n);
	if (avg < 0) avg -= 5;
	else avg += 5;
	int mid = arr[n / 2];
	int many = 0;
	
	int _max = -1;
	int findex = -1;
	int sindex = -1;
	for (int i = 0; i < 8001; i++) {
		if (fre[i] > _max) {
			_max = fre[i];
			findex = i;
			sindex = -1;
		}
		else if (_max == fre[i] && sindex == -1) {
			sindex = i;
		}
	}
	if (sindex == -1) many = findex;
	else many = sindex;
	
	int _range = arr[n - 1] - arr[0];
	cout << avg/10<< "\n" << mid << "\n" << many-4000 << "\n" << _range;
}