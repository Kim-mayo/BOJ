#include <iostream>
#include <vector>
using namespace std;
vector<int>pivona(46,-1);

int DP(int N) {
	if (N == 0)return pivona[N]=0;
	if (N == 1)return pivona[N]=1;

	if (pivona[N] != -1) return pivona[N];
	pivona[N] = DP(N - 2) + DP(N - 1);

	return pivona[N];
}

int main() {

	int N; cin >> N;
	
	DP(N);
	cout << pivona[N];
}