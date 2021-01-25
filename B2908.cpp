#include <iostream>
using namespace std;
char A[4];
char B[4];
int main() {

	//두수를 받아옴. A,B 734 893 -> 437 398 437!
	//734->437 

	cin >> A >> B;

	int a = (A[0] - '0') + (A[1] - '0') * 10 + (A[2] - '0') * 100;
	int b = (B[0] - '0') + (B[1] - '0') * 10 + (B[2] - '0') *100;

	if (a > b) cout << a;
	else cout << b;

}