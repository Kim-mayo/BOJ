#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int a, int b) {
	return b ? solution(b, a % b) : a;
}
int main() {

	int n; cin >> n;
	vector<int>nn;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		nn.push_back(a);
	}
	sort(nn.begin(), nn.end());
	vector<int>mm;
	for (int i = nn.size()-1; i > 0; i--) {
		mm.push_back(nn[i] - nn[i - 1]);
	}
	int ret = solution(mm[0], mm[1]);
	for (int i = 2; i < mm.size(); i++) {
		ret = solution(ret, mm[2]);
	}
	vector<int>num;
	int i;
	for (i = 1; i * i < ret; i++) {
		if (ret % i == 0) {
			num.push_back(i);
			num.push_back(ret/i);
		}
	}
	if (i * i == ret)num.push_back(i);
	sort(num.begin(), num.end());
	for (int i = 1; i < num.size(); i++) {
		cout << num[i] << " ";
	}


}