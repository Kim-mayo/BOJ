#include <iostream>
using namespace std;
char a[101];
int main() {

	//N��������, �״����޴°� ��� ���ϱ�
	int t; cin >> t;//5
	int sum = 0;
	cin >> a;//54321
	for (int i = 0; i <t; i++) {
		
		sum += a[i]-'0';
		

	}
	cout << sum;
}