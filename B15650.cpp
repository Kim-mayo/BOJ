#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int>sq;
bool used[9];
void backtracking(vector<int>seq,int s) {
	if (seq.size() == m) {
		for (int i = 0; i < m; i++) {
			cout << seq[i] << " ";
		}

			cout << "\n";
		
		return;
	}

	for (int i = s; i <= n; i++) {
		if (used[i] == true)continue;
		used[i] = true;
		seq.push_back(i);
		backtracking(seq,i+1);
		seq.pop_back();
		used[i] = false;
	}
}
int main() {

	cin >> n >> m;
	backtracking(sq,1);

}