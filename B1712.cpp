#include <iostream>
using namespace std;
int main() {

	int A, B, C;
	int bp = 0;
	cin >> A >> B >> C;

	if ((C - B) <= 0) cout << "-1";
	
	else {
		bp = A / (C - B) + 1;

		cout << bp;
	}
}