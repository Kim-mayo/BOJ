#include <iostream>
using namespace std;
char s[101];
int check[26];
bool ch[26];
int main() {

	for (int i = 0; i < 26; i++) {
		check[i] = -1;
		ch[i] = false;
	}
	cin >> s;
	for(int i = 0;s[i]!='\0';i++) {
			
			if (ch[s[i] - 'a'] == true) continue;
			else {
				check[s[i] - 'a'] = i;
				ch[s[i] - 'a'] = true;
			}

			
		
	}

	for (int i = 0; i < 26; i++) {
		cout << check[i] << " ";
	}
}