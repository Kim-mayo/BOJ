#include <iostream>
#include <cstring>
using namespace std;
char cro[101];
int main() {

	cin >> cro;
	int len = strlen(cro);
	int cnt = 0;
	for (int i = 0; i<len; i++) {

		if (cro[i] == 'c') {
			if (cro[i + 1] == '='&&(i+1)<len) {
				cnt++;
				i++;
			}
			else if (cro[i+1] == '-' && (i + 1) < len) {
				cnt++;
				i++;
			}
			else cnt++;
		}
		else if (cro[i] == 'd') {
			if (cro[i + 1] == 'z' && (i + 1) < len ) {
				if (cro[i + 2] == '=' && (i + 2) < len) {
					cnt++;
					i++;
					i++;
				}
				else cnt++;
			}
			else if (cro[i + 1] == '-' && (i + 1) < len) {
				cnt++;
				i++;
			}
			else cnt++;
		}
		else if (cro[i] == 'l') {
			if (cro[i + 1] == 'j' && (i + 1) < len) {
				cnt++;
				i++;
			}
			else cnt++;
		}
		else if (cro[i] == 'n') {
			if (cro[i + 1] == 'j' && (i + 1) < len) {
				cnt++;
				i++;
			}
			else cnt++;
		}
		else if (cro[i] == 's') {
			if (cro[i + 1] == '=' && (i + 1) < len) {
				cnt++;
				i++;
			}
			else cnt++;
		}
		else if (cro[i] == 'z') {
			if (cro[i + 1] == '=' && (i + 1) < len) {
				cnt++;
				i++;
			}
			else cnt++;
		}
		else cnt++;

	}
	cout << cnt;
}