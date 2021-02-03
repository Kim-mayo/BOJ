#include <iostream>
#include <stack>
using namespace std;

stack<char>st;
int main() {//출력초과 왜???????????????????????????

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		
		string ps;
		
		cin >> ps;
		int j;
		for (j = 0; j < ps.size(); j++) {
			if (ps[j] == '(') { st.push(ps[j]); }
			else {
				if (st.empty()) { cout << "NO\n"; break; }
				st.pop();
			}
			if (j == ps.size() - 1) {
				if (st.empty()) { cout << "YES\n"; }
				else {
					cout << "NO\n";
					while (!st.empty()) { st.pop(); }
				}
			}
		}
	}

}