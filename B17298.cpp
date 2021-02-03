#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int>st;
vector<int>Obig;
int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	Obig.resize(n);
	
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		Obig[i] = a;
	}

	for (int i = n - 1; i >= 0; i--) {
		int num = Obig[i];
		if (st.empty()) {
			Obig[i] = -1;
		}
		else {
			if (st.top() > Obig[i]) { Obig[i] = st.top(); }
			else {
				Obig[i] = -1;
				while (!st.empty()) {
					if (st.top() > num) { Obig[i] = st.top(); break; }
					st.pop();
				}

			}
		}
		st.push(num);
	}

	for (int i = 0; i < n; i++) {
		cout << Obig[i] << " ";
	}

}