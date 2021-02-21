#include <iostream>
#include <vector>
using namespace std;

#define m 1000000007
#define ll long long
ll n;
vector<vector<ll>>matrix;
vector<vector<ll>> multiple(vector<vector<ll>>& a, vector<vector<ll>>& b) {

	vector<vector<ll>>arr;
	arr.resize(a.size());
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[i].size(); j++) {
			ll p = 0;
			for (int k = 0; k < a[i].size(); k++) {
				p += (a[i][k] % m * b[k][j] % m) % m;
				p = p % m;
			}
			arr[i].push_back(p);
		}
	}
	return arr;

}
vector<vector<ll>> pow_(vector<vector<ll>>& matrix,ll k) {
	if (k == 1) return matrix;
	if (k == 0) return matrix;

	auto ret = pow_(matrix, k / 2);
	ret = multiple(ret, ret);
	if (k % 2 == 1)ret = multiple(ret, matrix);
	return ret;
}
int main() {

	cin >> n;
	matrix.resize(2, vector<ll>(2,1));
	matrix[1][1] = 0;
	vector<vector<ll>>mat;
	mat.resize(2, vector<ll>(1, 1));
	mat[1][0] = 0;
	auto val = pow_(matrix, n - 1);
	auto ret = multiple(val, mat);
	
	cout << (ret[0][0]) % m;

}