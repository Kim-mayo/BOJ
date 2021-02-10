#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>LIS1;
vector<int>LIS2;
vector<int>arr;
vector<int>path1;
vector<int>path2;
int lower_bound(vector<int>lis, int target, int size) {

	int mid = 0;
	int start = 0;
	int end = size;

	while (end > start) {

		mid = (start + end) / 2;

		if (lis[mid] >= target) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}
	return end;
}
int main() {

	int n; cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr[i] = a;
	}
	LIS1.push_back(arr[0]);
	path1.push_back(0);
	for (int i = 1; i < n; i++) {
		if (arr[i] > LIS1.back()) {
			LIS1.push_back(arr[i]);
			path1.push_back(LIS1.size()-1);
		}
		else {
			int pos = lower_bound(LIS1,arr[i], LIS1.size());
			LIS1[pos] = arr[i];
			path1.push_back(pos);
		}
	}
	LIS2.push_back(arr[n - 1]);
	path2.push_back(LIS2.size()-1);//그건아닌데..
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] > LIS2.back()) {
			LIS2.push_back(arr[i]);
			path2.push_back(LIS2.size()-1);
		}
		else {
			int pos = lower_bound(LIS2, arr[i], LIS2.size());
			LIS2[pos] = arr[i];
			path2.push_back(pos);
		}
	}
	reverse(path2.begin(), path2.end());
	int big = -1;
	for (int i = 0; i < path1.size(); i++) {
		big = max(big, path1[i] + path2[i]);
	}
	cout << big + 1;
}