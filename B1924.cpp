#include <iostream>
using namespace std;

int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int cal(int m, int d) {
	int yoil = d;
	for (int i = 0; i < m - 1; i++) {
		yoil += month[i];
	}
	return yoil % 7;
}
void Yoil(int n) {
	if (n == 1) cout << "MON";
	else if (n == 2)cout << "TUE";
	else if (n == 3)cout << "WED";
	else if (n == 4)cout << "THU";
	else if (n == 5)cout << "FRI";
	else if (n == 6)cout << "SAT";
	else cout << "SUN";
}
int main() {

	int mon, day; cin >> mon >> day;
	int a = cal(mon, day);
	Yoil(a);

}