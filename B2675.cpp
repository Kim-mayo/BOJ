#include <iostream>
using namespace std;
char s[21];
int main() {

	//문자열 S를 받고, 반복할 문자R,새문자열P
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {

		int R; cin >> R;
		cin >> s;
		for (int j = 0; s[j] != '\0'; j++) {
			for (int k = 0; k < R; k++) {
				cout << s[j];
			}
		}
		cout << "\n";
	}


}