#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int>seq;
bool used[9];
void backtracking(vector<int>seq) {
	if (seq.size() == m) {
		for (int i = 0; i < m; i++) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (used[i] == true) continue;
		used[i] = true;
		seq.push_back(i);
		backtracking(seq);
		seq.pop_back();
		used[i] = false;
	}
	return;
}
int main() {

	 cin >> n >> m;
	 backtracking(seq);


}