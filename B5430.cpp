#include <iostream>
#include <queue>
#include <vector>
using namespace std;

deque<int>dq;
int main() {

	int t; cin >> t;
	for (int i = 0; i < t; i++) {

		bool fr = true;
		bool error = false;
		string ac; cin >> ac;
		int num; cin >> num;
		
		int sum = 0;
		for (int j = 0;;j++) {
			char a; cin >> a;
			
			if ('0' <= a && a <= '9') {
				sum = sum * 10 + (a - '0');
			}
			else if (a == ',') {
				dq.push_back(sum);
				sum = 0;
			}
			else if (a == ']') break;
		}
		if (dq.size() < num) {
			dq.push_back(sum);
		}
		int k = 0;
		while (k<ac.size()) {

			if (ac[k] == 'R') {
				fr = !fr;
			}
			else {
				if (dq.empty()) {
					cout << "error\n";
					error = true;
					break;
				}
				else if (fr) {
					dq.pop_front();
				}
				else if (!fr) {
					dq.pop_back();
				}
			}
			k++;
		}
		int p = dq.size();
		if (!error)cout << "[";
		while (!dq.empty()) {
			if (fr) {
				int n = dq.front();
				dq.pop_front();
				cout << n;
			}
			else if (!fr) {
				int n = dq.back();
				dq.pop_back();
				cout << n;
			}
			if (p == 1)break;
			cout << ",";
			p--;
		}
		if (!error)cout << "]\n";


	}

}