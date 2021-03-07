#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define INF 1e9
vector<int>game;
int find(int v) {
	if (v == game[v])return v;
	else return game[v] = find(game[v]);
}
bool merge(int a, int b) {
	int A = find(a);
	int B = find(b);
	if (A == B)return true;
	else {
		game[A] = B;
		return false;
	}
}
void input() {

	int n, m; cin >> n >> m;
	game.resize(n);
	for (int i = 0; i < n; i++)game[i] = i;
	for (int i = 1; i <= m; i++) {

		int a, b; cin >> a >> b;
		if (merge(a, b)) {
			cout << i;
			return;
		}
		
	}
	cout << "0";

}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();

}