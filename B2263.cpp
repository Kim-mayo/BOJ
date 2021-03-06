#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define INF 1e9
vector<int>in;
vector<int>post;
vector<int>pre;
int num[100001];
int n;
void divide(int il,int ir,int pl, int pr) {
	if (il > ir || pl > pr)return;
	
	int index = 0;
	int root = post[pr];
	cout << root << " ";
	index = num[root];
	divide(il,index-1,pl,pl+(index-1-il));
	divide(index+1,ir,pl+(index-il),pr-1);
	return;
}

void input() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		in.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		post.push_back(a);
	}

	for (int i = 0; i < n; i++) {
		num[in[i]] = i;
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	divide(0, n - 1, 0,n - 1);

}