#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>>ab;
int main() {

	string a; cin >> a;
	string b; cin >> b;

	ab.resize(b.size()+1, vector<int>(a.size()+1));

	for (int i = 0; i <= b.size(); i++) {
		for (int j = 0; j <= a.size(); j++) {
			if (i == 0 || j == 0) { ab[i][j] = 0; }
			else {

				if (b[i - 1] == a[j - 1]) {
					ab[i][j] = ab[i - 1][j - 1] + 1;
				}
				else {
					ab[i][j] = max(ab[i][j - 1], ab[i - 1][j]);
				}

			}

		}
	}
	cout << ab[b.size()][a.size()];
}