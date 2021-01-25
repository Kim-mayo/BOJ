#include <iostream>
using namespace std;
char e[16];
int n[16];
int main() {

	cin >> e;
	for (int i = 0; e[i] != '\0'; i++) {

		if ('A' <= e[i] && e[i] <= 'C') n[i] = 3;
		else if ('D' <= e[i] && e[i] <= 'F') n[i] = 4;
		else if ('G' <= e[i] && e[i] <= 'I') n[i] = 5;
		else if ('J' <= e[i] && e[i] <= 'L') n[i] = 6;
		else if ('M' <= e[i] && e[i] <= 'O') n[i] = 7;
		else if ('P' <= e[i] && e[i] <= 'S') n[i] = 8;
		else if ('T' <= e[i] && e[i] <= 'V') n[i] = 9;
		else if ('W' <= e[i] && e[i] <= 'Z') n[i] = 10;

	}
	int sum = 0;
	for (int i = 0; n[i] != '\0'; i++) {
		sum += n[i];
	}

	cout << sum;

}