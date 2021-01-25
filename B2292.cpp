#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N; cin >> N;
	
	int sum = 2;
	int i = 0;
	for (i=0; sum <= N; i++) {

		sum += (6 * i);
		
	}
	if (N == 1) i = 1;
	cout << i;
	
}