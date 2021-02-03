#include <iostream>
#include <queue>
using namespace std;

queue<int>q;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string command; cin >> command;
		if (command == "push") { int num; cin >> num; q.push(num); }
		else if (command == "pop") {
			if (q.empty()) { cout << "-1\n"; continue; }
			int fr = q.front(); q.pop();
			cout << fr << "\n";
		}
		else if (command == "front") {
			if (q.empty()) { cout << "-1\n"; continue; }
			int fr = q.front(); cout << fr << "\n";
		}
		else if (command == "back") { 
			if (q.empty()) { cout << "-1\n"; continue; }
			int b = q.back(); cout << b << "\n";
		}
		else if (command == "size") {
			cout << q.size() << "\n";
		}
		else if (command == "empty") {
			if (q.empty()) cout << "1\n";
			else cout << "0\n";
		}
		for (int i = 0; i < command.size(); i++) command[i] = 0;
	}

}