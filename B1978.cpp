#include <iostream>
using namespace std;

int main() {

	int t; cin >> t;
	int cnt = 0;
	for (int i = 0; i < t; i++) {
		bool notsosu = false;
		
		int num; cin >> num;//1���Ҽ��ƴ�.
		if(num==1)continue;
		for (int j = 2; j < num; j++) {
			if (num % j == 0) notsosu = true;
		}
		if (!notsosu) {
			cnt++;
		}
	}
	cout << cnt;
}