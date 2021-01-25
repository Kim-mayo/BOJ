#include <iostream>
using namespace std;

int main() {

	int A, B, V;
	cin >> A >> B >> V;

	int n = 0;
	n = (V-B) / (A - B);
	if ((V - B) % (A - B) != 0) n = n + 1;
	cout << n;
	
}