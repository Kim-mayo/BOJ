#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>>bag;
vector<int>dp;
int main() {

	ios_base::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	bag.resize(N);
	dp.resize(K+1,0);
	for (int i = 0; i < N; i++) {
		int w, v; cin >> w >> v;
		bag.push_back({ w,v });	
	}

	for (int i = 0; i < bag.size(); i++) {
		int curr_w = bag[i].first;//6
		int curr_v = bag[i].second;//13
		for(int j=K ; j>= curr_w ; j--){
			if (dp[j - curr_w] + curr_v > dp[j]) dp[j] = dp[j - curr_w] + curr_v;
		}
	}
	cout << dp[K];

}