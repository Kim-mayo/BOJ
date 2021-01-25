#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int>trophy;
stack<int>st;
int main() {

	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	trophy.resize(N);
	for (int i = 0; i < N; i++) {

		int a; cin >> a;
		trophy[i] = a;

	}
	st.push(trophy[0]);
	for (int i = 1; i < trophy.size(); i++) {

		int high = st.top();
		if (trophy[i] > high) st.push(trophy[i]);
		else continue;

	}
	int left_size = st.size();
	cout << left_size << "\n";

	while (!st.empty()) {
		st.pop();
	}

	st.push(trophy[N - 1]);
	for (int i = trophy.size() - 2; i >= 0; i--) {
		int high = st.top();
		if (trophy[i] > high) st.push(trophy[i]);
		else continue;
	}
	int right_size = st.size();
	cout << right_size;
}