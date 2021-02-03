#include <iostream>
#include <queue>
using namespace std;

deque<int>card;
int main() {

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		card.push_back(i);
	}

	while (!card.empty()) {

		if (card.size() == 1) {
			cout << card.front();
			return 0;
		}
		card.pop_front();
		int top_ = card.front();
		card.pop_front();
		card.push_back(top_);

	}

}