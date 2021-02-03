#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char>st;
int main() {

	while (1) {

		string s;
		getline(cin, s);
		bool ok = true;
		if (s.size() == 1 && s[0] == '.') return 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') { st.push('('); }
			else if (s[i] == '[') { st.push('['); }
			else if (s[i] == ')') {
				if (st.empty()) ok = false;
				else if (st.top() == '(')  st.pop();
				else if (st.top() == '[') ok = false;
			}
			else if (s[i] == ']') {
				if (st.empty()) ok = false;
				else if (st.top() == '[')  st.pop();
				else if (st.top() == '(') ok = false;
			}
		}
		if (!st.empty() || ok == false) {
			cout << "no\n";
			while (!st.empty())st.pop();
		}
		else if (st.empty() && ok == true) {
				cout << "yes\n";
		}
	}
	
}