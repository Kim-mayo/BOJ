#include <iostream>
#include <algorithm>
using namespace std;
int com[8];
int uncom[8];
int main() {

	int sound[8];
	for (int i = 0; i < 8; i++) {

		cin >> sound[i];
		com[i] = sound[i];
		uncom[i] = sound[i];
	}
	sort(com+0,com+8);
	sort(uncom + 0, uncom + 8);
	reverse(uncom+0, uncom+8);

	int cnt_a = 0;
	int cnt_d = 0;
	for (int i = 0; i < 8; i++) {
		if (com[i] == sound[i]) cnt_a++;
		else if (uncom[i] == sound[i]) cnt_d++;
	}
	if (cnt_a == 8) cout << "ascending";
	else if (cnt_d == 8)cout << "descending";
	else cout << "mixed";

}