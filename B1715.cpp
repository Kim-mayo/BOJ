#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> card;
vector<int>card_sum;
int N;
priority_queue<int>pq;

void cardcard() {

	for (int i = 0; i < N; i++) {
		pq.push(-card[i]);
	}

	while (pq.size() > 1) {
		int small1 = -pq.top();
		pq.pop();
		int small2 = -pq.top();
		pq.pop();
		int sum = small1 + small2;
		card_sum.push_back(sum);
		pq.push(-sum);
	}
	
	return;
}

int main() {

	cin >> N;
	card.resize(N, 0);
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		card[i] = a;
	}
	cardcard();
	int sum=0;
	for (int i = 0; i < card_sum.size(); i++) {
		sum += card_sum[i];
	}
	cout << sum;
}
//getline(cin,stringtypeÀÌ¸§)