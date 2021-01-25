#include <iostream>
using namespace std;

int main() {

	int bird; cin >> bird;
	int remain_b=bird;
	int sec = 0;
	int i = 1;
	while (1) {

		if (remain_b < i) {
			i = 1;
		}
		remain_b = remain_b - i;
		sec++;
		i++;
		if (remain_b == 0) break;


		
	}
	
	cout << sec;
}