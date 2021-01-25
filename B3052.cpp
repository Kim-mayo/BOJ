#include <iostream>
using namespace std;
int arr[10];
int check[42];
int main() {

	int N;
	int cnt=0;
	
	for (int i = 0; i < 10; i++) {
		cin >> N;
		arr[i] = N % 42;
		check[arr[i]] = 1;
		
	}

	for (int i = 0; i < 42; i++) {
		if (check[i] == 1) cnt++;
	}
	
	cout << cnt;
}