#include <iostream>
using namespace std;
char s[1000010];
int main() {

	cin.getline(s, 1000005);

	int len = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		len++;
	}

	int left = 0;
	int right = len - 1;

	while (1) {
		if (s[left] != ' ') break; 
		else left++; //1
	}
	while (1) {
		if (s[right] != ' ') break; 
		else right--; //0
	}
	if (left > right) {//     a      ->5,5
		cout << "0"; 
		return 0;
	}
	int cnt = 0;
	for (int i = left; i <= right; i++) {

		if (s[i] == ' ') cnt++;

	}
	cout << cnt+1;

}