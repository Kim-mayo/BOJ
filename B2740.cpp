#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>a;
vector<vector<int>>b;
vector<vector<int>>c;
int an, bm;
void input() {
	int am; cin >> an >> am;
	
	a.resize(an);
	for (int i = 0; i < an; i++) {	
		for (int j = 0; j < am; j++) {
			int p; cin >> p;
			a[i].push_back(p);
		}
	}
	int bn; cin >> bn >> bm;
	
	b.resize(bn);
	for (int i = 0; i < bn; i++) {
		for (int j = 0; j < bm; j++) {
			int p; cin >> p;
			b[i].push_back(p);
		}
	}
}
void multiple() {

	c.resize(a.size());
	for (int i = 0; i < a.size(); i++) {//2차원이면 사이즈를부르면 행사이즈.
		for (int j = 0; j < b[0].size(); j++) {
			int p = 0;
			for (int k = 0; k < a[0].size(); k++) {
				p += a[i][k] * b[k][j];
			}
			c[i].push_back(p);
		}
	}
}
int main() {

	input();
	multiple();
	for (int i = 0; i < c.size(); i++) {
		for (int j = 0; j < c[i].size(); j++) {
			cout << c[i][j] << " ";
		}
		cout << "\n";
	}
}