#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>//logn
#include <unordered_map>//1
#include <set>//1122223->123
using namespace std;
map<string, int>book;
set<int>setset;
vector <string> bb;
int main() {

	ios_base::sync_with_stdio(false);
	int N; cin >> N;

	for (int i = 0; i < N; i++) {

		string a; cin >> a;
		book[a]++;
		book.insert({ a, i });
		setset.insert(i);

	}
	

	int bestseller=0;
	for (auto it = book.begin(); it != book.end(); it++) {
		bestseller = max(bestseller, it->second);
	}
	
	for (auto it = book.begin(); it != book.end(); it++) {
		if (it->second == bestseller) {
			bb.push_back(it->first);
		}
	}
	sort(bb.begin(), bb.end());
	cout << bb[0];

}