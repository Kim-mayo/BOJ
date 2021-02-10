#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

deque<int>dq;
int main() {

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		
	
			int oper2 = 0, oper3 = 0;
			if (dq.front() == num) { dq.pop_front(); }
			else {
				for (int j = 0; j < dq.size(); j++) {
					int fr = dq.front();
					dq.pop_front();
					dq.push_back(fr);
					if (num == fr)oper2 = j;
				}
				oper3 = dq.size() - oper2;
				if (oper2 >= oper3) {
					for (int k = 0; k < oper3; k++) {
						int back = dq.back();
						dq.pop_back();
						dq.push_front(back);
					}
				}
				else {
					for (int k = 0; k < oper2; k++) {
						int fr = dq.front();
						dq.pop_front();
						//if (fr == num)continue;
						dq.push_back(fr);
					}
				}
				dq.pop_front();
				cnt += min(oper2, oper3);
				
			}
			
			
		


	}
	cout << cnt;
}