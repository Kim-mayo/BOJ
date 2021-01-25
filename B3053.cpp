#include <iostream>
#include <cmath>
using namespace std;

#define Pi 3.14159265359
int main() {

	int R; cin >> R;
	double ucl = Pi * pow(R, 2);
	double taxi = 2 * pow(R, 2);
	cout << fixed;
	cout.precision(7);
	cout << ucl << "\n" << taxi;

}