#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
bool check(string sq) {
	
	if (sq.size() == 1) return true;

	
	for (int i = 1; i<=sq.size()/2; i++) {

		string a = sq.substr(sq.size() -i , i);
		string b = sq.substr(sq.size() -(2*i), i);
		if (a == b) return false;
	}

	return true;
}
bool fin = false;
string  solution(int length,string sq) {

	if (length == n) {
		fin = true;
		return sq;
	}
	string ret;
	for (int i = 1; i <= 3; i++) {

		sq.push_back(i+'0');
		if (check(sq) == false) {
			sq.pop_back();
			continue;
		}
		ret = solution(length + 1, sq);
		if (fin == true) return ret;
		sq.pop_back();
	}
	return ret;
}
int main() {

	cin >> n;
	string a = solution(0,"");

	cout << a;

}