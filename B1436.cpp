#include <iostream>
using namespace std;
int arr[10001];
int main() {

	int N; cin >> N;

	int i = 666;
	int j = 1;
	while (j<=N) {

		int me = i;
		while (me>0) {
			if (me % 1000 == 666) {
				arr[j] = i;
				j++; 
				break;
			}
			me = me / 10;
		}
		i++;
	}
	cout << arr[N];
}