#include <iostream>
using namespace std;

int arr[2];
int main() {

	int cnt = 0;
	int N; cin >> N;
	int New = N;
	while (1) {
		
		
		
		if (New < 10) {
			arr[0] = 0;
			arr[1] = New;
		}

		else {//26,68
			arr[0] = New / 10;//2,6
			arr[1] = New % 10;//6,8
		}
		int sum = 0;
		sum = arr[0] + arr[1];//8,14

		New = arr[1]*10 + sum%10;//68,84

		cnt++;

		if (New == N) break;
		

	}

	cout << cnt;

}