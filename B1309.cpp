#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>hutch;
int main() {

	int n; cin >> n;
	hutch.resize(3, vector<int>(n, 0));
	hutch[0][0] = 1;
	hutch[1][0] = 1;
	hutch[2][0] = 1;
	for (int i = 1; i < n; i++) {
		hutch[0][i] = (hutch[0][i - 1] + hutch[1][i - 1] + hutch[2][i - 1])%9901;
		hutch[1][i] = (hutch[0][i - 1] + hutch[2][i - 1])%9901;
		hutch[2][i] = (hutch[0][i - 1] + hutch[1][i - 1])%9901;
	}
	cout << (hutch[0][n - 1] + hutch[1][n - 1] + hutch[2][n - 1])%9901;
}