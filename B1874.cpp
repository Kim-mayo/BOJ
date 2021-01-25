#include <iostream>
#include <vector>
using namespace std;
vector <int> answer;
vector <char>pm;

int st[100001];
int top = -1;
void push(int a) {
	top++;
	st[top] = a;
	pm.push_back('+');
}
void pop() {
	top--;
	pm.push_back('-');
}

int main() {

	int n; cin >> n;
	answer.resize(n,0);
	for (int i = 0; i < n; i++) {
		cin >> answer[i];
	}
	int j = 0;
	for (int i = 1; i <= n; i++) {
		if (answer[j] > i) {
			push(i);
		}
		else if (answer[j] < i) {
			if (top!=-1&&st[top] == answer[j]) {
				pop();
				j++;
				i--;
			}
			else {
				cout << "NO";
				return 0;
			}
		}
		else if (answer[j] == i) {
			push(i);
			pop();
			j++;
		}
	}

	while (top != -1) {
		if (st[top] == answer[j]) {
			pop();
			j++;
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < pm.size(); i++) {
		cout << pm[i] << "\n";
	}
}