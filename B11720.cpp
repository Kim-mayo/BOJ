#include <iostream>
using namespace std;
char a[101];
int main() {

	//N번돌리고, 그다음받는값 계속 더하기
	int t; cin >> t;//5
	int sum = 0;
	cin >> a;//54321
	for (int i = 0; i <t; i++) {
		
		sum += a[i]-'0';
		

	}
	cout << sum;
}