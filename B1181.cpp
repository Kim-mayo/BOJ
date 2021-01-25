#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string>word;

bool compare(string a, string b) {

	if (a.size() == b.size()) return a < b;
	else return a.size() < b.size();
}

int main() {

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		string a; cin >> a;
		word.push_back(a);
	}
	
	sort(word.begin(), word.end(),compare);
	word.erase(unique(word.begin(), word.end()), word.end());
	for (int i = 0; i < word.size(); i++) {
		cout << word[i] << "\n";
	}


}