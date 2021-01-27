#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int>seq;
void backtracking(vector<int>seq, int s) {
	if (seq.size() == m) {
		for (int i = 0; i < m; i++) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = s; i <= n; i++) {
		seq.push_back(i);
		backtracking(seq, i);
		seq.pop_back();
	}
}
int main() {
	cin >> n >> m;
	backtracking(seq, 1);
}