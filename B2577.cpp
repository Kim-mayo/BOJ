#include <iostream>
using namespace std;
int cnt[10];
int arr[10];

int main() {

	int A, B, C;
	cin >> A >> B >> C;

	int num = 1;
	num = A * B * C;
	
	int an = 0;
	int n = num;
	while (1) {
		
		arr[an] = n % 10;
		if (n == 0)break;
		n = n / 10;
		
		an++;


	}
	

	
	for (int i = 0;i<10; i++) {
		for (int j = 0;j<an; j++) {
			if (arr[j] == i) cnt[i]++;
		}
		cout << cnt[i] << "\n";
	}
}