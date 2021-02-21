#include <iostream>
using namespace std;

bool arr[10001];
void crimi() {

	for (int i = 1; i < 10001; i++) {

		int n = i;
		int num = n;
		while (1) {
			if (n == 0)break;
			num += n%10;
			n /= 10;
		}
		arr[num] = true;
	}

}
int main() {

	crimi();
	for (int i = 1; i < 10001; i++) {
		if (arr[i] == false)cout << i << "\n";
	}

}