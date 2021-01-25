#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> num;
int main() {

	ios_base::sync_with_stdio(false);
	int N, K; cin >> N >> K;
	num.resize(N+1);
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		num[i] = a;
	}
	sort(num.begin()+1, num.end());
	cout << num[K];

}