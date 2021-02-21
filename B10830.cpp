#include <iostream>
#include <vector>
using namespace std;

#define K 1000
#define ll long long
vector<vector<ll>>mat;
ll k;
void input() {

	ll n; cin >> n >> k;
	mat.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ll a; cin >> a;
			mat[i].push_back(a);
		}
	}
}
vector<vector<ll>> multiple(vector<vector<ll>>& a, vector<vector<ll>>& b) {

	vector<vector<ll>>remat;
	remat.resize(mat.size());

	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat.size(); j++) {
			ll p = 0;
			for (int k = 0; k < mat.size(); k++) {

				p += (a[i][k] * b[k][j]) % K;
				p = p % K;
			}
			remat[i].push_back(p % K);
		}
	}

	return remat;
}
vector<vector<ll>> pow_(vector<vector<ll>>& mat, ll k) {

	if (k == 1) {
		return mat;
	}

	auto ret = pow_(mat, k/2);
	ret = multiple(ret, ret);
	if (k % 2 == 1)ret = multiple(ret,mat);
	return ret;

}
int main() {

	input();
	auto matrix = pow_(mat, k);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) {
			cout << matrix[i][j]%K << " ";
		}
		cout << "\n";
	}
}