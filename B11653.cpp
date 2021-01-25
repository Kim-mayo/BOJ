#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>Prime;
int main() {

	int n; cin >> n;//1�̸� ����0 , �������� ���μ���������
	if (n == 1) return 0;
	int prime = 2;
	while (prime * prime <= n) {
		if (n % prime == 0) {
			Prime.push_back(prime);
			n /= prime;
		}
		else prime++;
	}
	if (n > 1) Prime.push_back(n);

	sort(Prime.begin(), Prime.end());
	for (int i = 0; i < Prime.size(); i++) {
		cout << Prime[i] << "\n";
	}
}