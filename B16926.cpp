#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, r;
vector<vector<int>>arr;
vector<vector<int>>rot;
queue<int>q;
void Rotate(int u, int v,int endcol, int endrow) {//0,0,4,4

	// > V < ^ 
	
	for (int i = v; i < endcol; i++) {
		q.push(arr[u][i]);
	}
	for (int i = u+1; i < endrow; i++) {
		q.push(arr[i][endcol - 1]);
	}
	for (int i = endcol - 2; i >= v; i--) {
		q.push(arr[endrow - 1][i]);
	}
	for (int i = endrow - 2; i > u; i--) {
		q.push(arr[i][v]);
	}
	for (int i = 0; i < r; i++) {
		int fr = q.front();
		q.pop();
		q.push(fr);
	}

	for (int i = v; i < endcol; i++) {
		rot[u][i] = q.front();
		q.pop();
	}
	for (int i = u + 1; i < endrow; i++) {
		rot[i][endcol - 1] = q.front();
		q.pop();
	}
	for (int i = endcol - 2; i >= v; i--) {
		rot[endrow - 1][i] = q.front();
		q.pop();
	}
	for (int i = endrow - 2; i > u; i--) {
		rot[i][v] = q.front();
		q.pop();
	}

}
int main() {

	cin >> n >> m >> r;
	arr.resize(n);
	rot.resize(n,vector<int>(m,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
			arr[i].push_back(a);
		}
	}
	int s = 0, e = 0;
	for (int i = 0; i < (min(n, m)) / 2; i++) {
		Rotate(s,e,m-s,n-e);
		s++;
		e++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << rot[i][j] << " ";
		}
		cout << "\n";
	}

}