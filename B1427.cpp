#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>num;
int main() {

	int N; cin >> N;
	
	int i = 0;
	while (N>=1) {

		
		num.push_back( N % 10);
		N = N / 10;
		i++;

	}

	sort(num.begin(), num.end());
	for (int i = num.size()-1; i >= 0; i--) {
		cout << num[i];
	}

}