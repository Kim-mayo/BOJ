#include <iostream>
#include <string>
using namespace std;

int main() {

	string document;
	string search;

	getline(cin, document);
	getline(cin, search);
	int cnt = 0;
	int pos = 0;
	while (1) {
		
		int find_ = document.find(search,pos);
		if (find_ == string::npos) break;
		else {
			cnt++;
			pos = find_ + search.size();
		}
	}
	cout << cnt;
}