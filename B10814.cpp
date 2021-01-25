#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<int,pair<int, string>>> mem;
int main() {

	int n; cin >> n;

	for (int i = 0; i < n; i++) {

		int y; string name; cin >> y >> name;

		mem.push_back({ y,{i,name} });

	}
	sort(mem.begin(),mem.end());

	for (int i = 0; i < n; i++) {
		int year = mem[i].first;
		string namename = mem[i].second.second;

		cout << year << " " << namename << "\n";
	}

}