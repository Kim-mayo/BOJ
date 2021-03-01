#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define INF 2e9
vector<long long>square;
void prepare() {
	long long value = 1;
	square.push_back(0);
	while (value<INF) {
		square.push_back(value);
		value *= 2;
	}
}
long long solution(int num) {

	long long curr = 0;
	long long sum = 0;
	int i = 1;
	if (num > 0) {
		while (1) {

			sum += curr * 4 + square[i] - square[i - 1];
			
			if (num<=square[i]&&square[i-1]<num) {
				long long gap = square[i] - num;
				sum -= gap;
				return sum;
			}
			
			curr = square[i];
			i++;
		}
	}
	else {
		while(1) {

			sum += curr + square[i] * 3;

			if (-num<=square[i]&&square[i-1]<-num) {
				long long gap = square[i] + num;
				sum -= gap;
				return sum;
			}
			curr = square[i];
			i++;

		}
	}
}
void input() {
	prepare();
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int a; cin >> a;
		if (a == 0) {
			cout << "0\n";
			continue;
		}
		
		cout << solution(a) << "\n";

	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();

}