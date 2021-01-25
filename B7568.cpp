#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>>info;
vector<int>Rank;
int main() {

	int N; cin >> N;
	info.resize(N);
	Rank.resize(N);
	for (int i = 0; i < N; i++) {
		int w, h; cin >> w >> h;
		info[i] = { w,h };
	}
	int me = 0;
	while (me<N) {
		int cnt = 0;
		int me_w = info[me].first;
		int me_h = info[me].second;
		for (int i = 0; i < N; i++) {
			if (me == i)continue;
			if (me_w < info[i].first && me_h < info[i].second) {
				cnt++;
			}
			Rank[me] = cnt + 1;
		}
		me++;
	}
	for (int i = 0; i < N; i++) {
		cout << Rank[i] << " ";
	}
}