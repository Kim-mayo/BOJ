#include <iostream>
#include <vector>
using namespace std;

vector <int> bj;

int main() {

	int n, m; cin >> n >> m;
	bj.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> bj[i];
	}
	int sum = 0;
	int cha = 0;
	int com = m;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				sum = bj[i] + bj[j] + bj[k];
				if (sum == m) {
					cout << m;
					return 0;
				}
				else if (sum > m) continue;
				else if (sum < m) { 
					cha = m - sum; 
					if (cha < com) com = cha;
					
				}
			}
		}
	}
	
	cout << m-com;
}