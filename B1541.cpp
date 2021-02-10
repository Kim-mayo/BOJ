#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

	string s; cin >> s;
	int sum = 0;
	int minus = 0;
	int result = 0;
	for (int i = 0; i < s.size(); i++) {
		
		if ('0' <= s[i] && s[i] <= '9') {
			sum = sum * 10 + (s[i] - '0');
		}
		
		else if(s[i]=='-'||s[i]=='+') {
			if (minus>=1) {
				result -= sum;
				sum = 0;
			}
			else {
				result += sum;
				sum = 0;
			}
			if (s[i] == '-')minus++;
		}
	}
	if (minus == 0) cout << result + sum;
	else cout << result - sum;
}