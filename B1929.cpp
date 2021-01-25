#include <iostream>
#include <vector>
using namespace std;
vector<int>prime;
bool ok[1000001];
int main() {

	int M, N; cin >> M >> N;
	//prime.resize(N);
	for (int i = 2; i <=N; i++) {
		ok[i] = true;
	}
	
	for (int i = 2; i * i <= N; i++) {
		if (ok[i] == false) continue;
		for (int j = i * i; j <= N; j+=i) {
			ok[j] = false;
		}
	}

	for (int i = M; i <= N; i++) {
		if (ok[i] == true) prime.push_back(i);	
	}

	for (int i = 0; i < prime.size(); i++) {
		cout << prime[i] << "\n";
	}
}