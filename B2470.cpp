#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

#define INF 1e9

vector<int>liquid;
void solution() {

	int fr = 0;
	int rear = liquid.size() - 1;
	int val1 = 0, val2 = 0;
	int mingap = INF;
	while (fr != rear) {

		if (liquid[fr] + liquid[rear] < 0) {
			if (mingap > abs(liquid[fr] + liquid[rear])) {
				val1 = liquid[fr];
				val2 = liquid[rear];
				mingap = abs(val2 + val1);
			}
			fr++;
		}
		else if (liquid[fr] + liquid[rear] > 0) {
			if (mingap > abs(liquid[fr] + liquid[rear])) {
				val1 = liquid[fr];
				val2 = liquid[rear];
				mingap = abs(val2 + val1);
			}
			rear--;
		}
		else if(liquid[fr]+liquid[rear]==0){
			cout << liquid[fr] << " " << liquid[rear];
			return;
		}
	}
	cout << val1 << " " << val2;

}
void input() {

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		liquid.push_back(a);
	}
	sort(liquid.begin(), liquid.end());

	if (*liquid.begin() >= 0) {
		cout << liquid[0] << " " << liquid[1]; return;
	}
	else if (liquid.back() <= 0) {
		cout << liquid[liquid.size() - 2] << " " << liquid[liquid.size() - 1]; return;
	}

	solution();
}
int main() {

	ios_base::sync_with_stdio(false);
	input();
	

}