#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n; cin >> n;
	
	vector<int>num;
	
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int numb = i;
		while (1) {
			if (numb == 0)break;
			num.push_back(numb % 10);
			numb /= 10;
		}
		bool ok = true;
		int cha = 100;
		for (int j = 1; j < num.size(); j++) {
			if (cha == 100) {
				cha = num[j] - num[j - 1];
			}
			else {
				if (cha == num[j] - num[j - 1])continue;
				else ok = false;
			}
		}
		if (ok == true)cnt++;
		num.clear();
	}
	cout << cnt;
}