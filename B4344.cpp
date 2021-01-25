#include <iostream>
using namespace std;
int score[1000];
int main() {
	//일단 점수들을 배열로 받아
	//평균구해, 평균보다 높은 애들 카운트해 
	//카운트값 나누기 학생수*100 = 정답쓰
	
	
	int tc, n;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> n;
		int sum = 0;
		double	avg = 0;
		int cnt = 0;
		double cri = 0;
		for (int j = 0; j < n; j++) {
			cin >> score[j];
			sum += score[j];
		}
		avg = (double)sum / n;

		for (int j = 0; j < n; j++) {
			if (score[j] > avg) cnt++;
		}
		cri = (double) cnt * 100 / n;
		cout << fixed;
		cout.precision(3);
		cout << cri << "%" <<"\n";
	}
}