#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

deque<char>dq[4];
void how(int RL,int check[4], int rotgear,int rotdi) {

	if (RL == 1) {//오른쪽으로가기 나는 2번필요 다음은 6번필요
		if (rotgear == 3) return;
		int nextgear = rotgear + 1;
		int a = dq[rotgear].front();
		dq[rotgear].pop_front();
		int b = dq[rotgear].front();
		dq[rotgear].pop_front();
		int c = dq[nextgear].back();
		dq[nextgear].pop_back();

		if (dq[rotgear].front() != dq[nextgear].back()) {
			dq[rotgear].push_front(b);
			dq[rotgear].push_front(a);
			dq[nextgear].push_back(c);
			if (rotdi == 1) {
				check[nextgear] = -1;
				how(RL, check, nextgear, -1);
			}
			else {
				check[nextgear] = 1;
				how(RL, check, nextgear, 1);
			}

		}
		else {
			dq[rotgear].push_front(b);
			dq[rotgear].push_front(a);
			dq[nextgear].push_back(c);
		}
	}
	else {//RL==-1 왼쪽으로 가기 나는 6번 다음은2번보기
		if (rotgear == 0) return;
		int nextgear = rotgear - 1;
		int a = dq[rotgear].back();
		dq[rotgear].pop_back();
		int b = dq[nextgear].front();
		dq[nextgear].pop_front();
		int c = dq[nextgear].front();
		dq[nextgear].pop_front();

		if (dq[rotgear].back() != dq[nextgear].front()) {
			dq[rotgear].push_back(a);
			dq[nextgear].push_front(c);
			dq[nextgear].push_front(b);
			if (rotdi == 1) {
				check[nextgear] = -1;
				how(RL, check, nextgear, -1);
			}
			else {
				check[nextgear] = 1;
				how(RL, check, nextgear, 1);
			}
		}
		else {
			dq[rotgear].push_back(a);
			dq[nextgear].push_front(c);
			dq[nextgear].push_front(b);
		}

	}
}
void rotate(int check[4]) {

	for (int i = 0; i < 4; i++) {
		if (check[i] == -1) {//unclock
			int front = dq[i].front();
			dq[i].pop_front();
			dq[i].push_back(front);
		}
		else if (check[i] == 1) {//clock
			int back = dq[i].back();
			dq[i].pop_back();
			dq[i].push_front(back);
		}
	}

}
int main() {
	//톱니바퀴 n==0 s==1
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			char a; cin >> a;
			dq[i].push_back(a);
		}

	}
	int rotn; cin >> rotn;
	int rotgear, rotdi;
	for (int i = 0; i < rotn; i++) {
		cin >> rotgear >> rotdi;
		rotgear--;
		int check[4] = { 0,0,0,0 };
		check[rotgear] = rotdi;
		how(1, check, rotgear, rotdi);
		how(-1, check, rotgear, rotdi);
		rotate(check);
	}

	int score=0;
	for (int i = 0; i < 4; i++) {
		score += (dq[i].front() - '0')*pow(2,i);
	}
	cout << score;

}