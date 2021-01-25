#include <iostream>
#include <vector>
using namespace std;
vector < int > sequence;
int main() {

	int n; cin >> n;
	sequence.resize(n+1);
	sequence[1] = 1;
	sequence[2] = 2;	

	for (int i = 3; i <= n; i++) {
		sequence[i] = sequence[i - 1] + sequence[i - 2];
		sequence[i] %= 15746;
	}

	cout << sequence[n]%15746;

}