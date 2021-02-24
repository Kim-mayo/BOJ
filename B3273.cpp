#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>sq;
int x;
int Two_pointer() {
	
	int cnt = 0;
	int i = 0;
	int j = sq.size() - 1;

	while (i < j) {

		if (sq[i] + sq[j] > x) {
			j--;
		}
		else if (sq[i] + sq[j] < x) {
			i++;
		}
		else if (sq[i] + sq[j] == x) {
			cnt++;
			i++;
		}

	}

	return cnt;
}
void input() {

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		sq.push_back(a);
	}
	cin >> x;
	sort(sq.begin(), sq.end());
}
int main() {

	input();
	cout << Two_pointer();

}