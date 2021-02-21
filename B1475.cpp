#include <iostream>
using namespace std;

int room[10];
int main() {

	int n; cin >> n;
	if (n == 0) {
		cout << "1";
		return 0;
	}
	int check = 0;
	while (1) {
		if (n == 0)break;
		
		if (n % 10 == 6 || n % 10 == 9) {
			check++;
			if (check == 2) {
				room[9] += 1;
				check = 0;
			}
		}
		else{ 
			room[n % 10] += 1;
		}
		n /= 10;
	}
	if (check != 0) {
		room[9] += 1;
	}
	int big = -1;
	for (int i = 0; i < 10; i++) {
		if (big < room[i]) {
			big = room[i];
		}
	}
	cout << big;
}