#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
string tree[65];
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); //cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}
}
//string Quad_tree(int row, int col, int size) {
//
//	if (size == 1) {
//		if (tree[row][col] == '0') {
//		
//			return "0";
//		}
//		else {
//			
//			return "1";
//		}
//	}
//
//	string a = Quad_tree(row, col, size / 2);
//	
//	string b = Quad_tree(row, col + size / 2, size / 2);
//	
//	string c = Quad_tree(row + size / 2, col, size / 2);
//	
//	string d = Quad_tree(row + size / 2, col + size / 2, size / 2);
//	
//
//	if (a == "0" && b == "0" && c == "0" && d == "0") return "0";
//	else if (a == "1" && b == "1" && c == "1" && d == "1") return "1";
//	else {
//		return "(" + a + b + c + d + ")";
//	}
//}

void Quad(int row, int col, int n) {
	
	if (n == 1) {
		cout << tree[row][col]; return;
	}
	int zero = 0;
	int one = 0;
	for (int i = row; i <row+n ; i++) {
		for (int j = col; j <col+n ; j++) {
			if (tree[i][j] == '0')zero++;
			else one++;
		}
	}
	if (zero == n*n)cout << "0";
	else if (one == n*n)cout << "1";
	else {
		cout << "(";
		Quad(row, col, n / 2);
		Quad(row, col + n / 2, n / 2);
		Quad(row + n / 2, col, n / 2);
		Quad(row + n / 2, col + n / 2, n / 2);
		cout << ")";
	}
}

int main() {

	input();
	Quad(0,0,n);

}