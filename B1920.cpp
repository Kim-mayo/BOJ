#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> A;
vector <int> B;

int Binary_s(int key) {
	
	
	int start = 0;
	int end = A.size()-1;

	while (start<=end) {

		int mid = (start + end) / 2;

		if (key > A[mid]) start = mid + 1;
		else if (key < A[mid]) end = mid - 1;
		else if (key == A[mid]) return 1; 
		
	}

	return 0;

}

int main() {

	int N; cin >> N;

	A.resize(N);
	
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		A[i] = num;
	}
	sort(A.begin(), A.end());
	int  M; cin >> M;

	B.resize(M);

	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		B[i] = num;
	}
	
		
	for (int i = 0; i < M; i++) {
		cout << Binary_s(B[i]) << "\n";
	}

}