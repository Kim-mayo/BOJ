#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>>paper;
void input() {
	cin >> n;
	paper.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a; cin >> a;
			paper[i].push_back(a);
		}
	}
}
int dx[9] = { 0,0,0,1,1,1,2,2,2 };
int dy[9] = { 0,1,2,0,1,2,0,1,2 };
pair<int,pair<int,int>> Division(int row, int col, int n) {

	if (n == 1) {
		if (paper[row][col] == -1)return { 1,{0,0} };
		else if (paper[row][col] == 0)return { 0,{1,0} };
		else return { 0,{0,1} };
	}
	int maone = 0;
	int zero = 0;
	int plone = 0;
	for (int i = 0; i < 9; i++) {
		auto it = Division(row + dx[i]*(n/3), col + dy[i]*(n/3), n / 3);
		maone += it.first;
		zero += it.second.first;
		plone += it.second.second;
	}
	if (maone == 9 && zero == 0 && plone == 0) return { 1,{0,0} };
	else if (maone == 0 && zero == 9 && plone == 0) return { 0,{1,0} };
	else if (maone == 0 && zero == 0 && plone == 9) return { 0,{0,1} };
	else {
		return { maone,{zero,plone} };
	}

	


}
int main() {

	input();
	auto DIV = Division(0,0,n);
	cout << DIV.first << "\n" << DIV.second.first << "\n" << DIV.second.second;
	
}