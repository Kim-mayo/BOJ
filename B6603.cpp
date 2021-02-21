#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>arr;
vector<bool>visit;
vector<int>space;
void solution(int index,int pick) {

	if (pick==6) {
		for (int i = 0; i < visit.size(); i++) {
			if (visit[i] == true)cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = index; i < arr.size(); i++) {
		if (visit[i] == true)continue;
		visit[i] = true;
		solution(i + 1,pick+1);
		visit[i] = false;
	}

}
int main() {
	/*for (int i = 1; i < 6; i++) {
		space.push_back(6-i);
	}
	do {
		for (int i = 0; i < 5; i++) {
			cout << space[i] << " ";
		}
		cout << "\n";
	} while (prev_permutation(space.begin(), space.end()));*/
	while (1) {
		int n; cin >> n;
		if (n == 0) return 0;

		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			arr.push_back(a);
		}
		visit.resize(arr.size(), false);
		//solution(0,0);
		// 1 2 3 4 오름차순 정렬이 되어있어야 올바른 결과를 출력한다.
		space.clear();
		space.resize(n, 1);
		for (int i = 0; i < 6; i++) {
			space[i] = 0;
		}
		do {
			for (int i = 0; i < space.size(); i++) {
				if (space[i] == 0)cout << arr[i] << " ";
			}
			cout << "\n";
		} while (next_permutation(space.begin(), space.end()));

		arr.clear();
		cout << "\n";
	}


}