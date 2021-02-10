	#include <iostream>
	#include <map>
	#include <string>
	using namespace std;

	int main() {

		int t; cin >> t;
		for (int i = 0; i < t; i++) {

			int n; cin >> n;
			map<string, int>cos;
			for (int j = 0; j < n; j++) {

				string a; cin >> a;
				string b; cin >> b;
				if (cos.find(b) == cos.end()) {
					cos[b] = 2;
				}
				else {
					cos[b]++;
				}
			}
			int mul = 1;
			for (auto it = cos.begin(); it != cos.end(); it++) {

				mul *= (it->second);

			}
			mul -= 1;
			cout << mul << "\n";
		}

	}