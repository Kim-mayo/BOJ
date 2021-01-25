#include <iostream>
using namespace std;
int arr[1000];
int main() {

	int t; cin >> t;
	int score;
	int H = 0;
	for (int i = 0; i < t; i++) {
		cin >> score;
		if (H < score) H = score;
		arr[i] = score;
	}
	double sum = 0,avg=0;
	for (int i = 0; i < t; i++) {
		sum += (double)arr[i] * 100/H;
	}
	avg =sum / t;
	cout << fixed;
	cout.precision(10);
	cout << avg;


}