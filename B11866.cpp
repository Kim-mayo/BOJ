#include <iostream>
#include <queue>
using namespace std;

queue<int>q;
vector<int>arr;
int main() {

	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++)q.push(i + 1);

	int i = 1;
	while (!q.empty()) {

		if (i % k == 0) {
			int pop_ = q.front();
			arr.push_back(pop_);
			q.pop();
			i++;
		}

		else {
			int fr = q.front();
			q.pop();
			q.push(fr);
			i++;
		}

	}
	cout << "<";
	for (int i = 0; i < arr.size()-1; i++) {
		cout << arr[i] << ", ";
	}
	cout << arr[arr.size()-1] << ">";

}