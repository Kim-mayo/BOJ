#include <iostream>
using namespace std;
int score[1000];
int main() {
	//�ϴ� �������� �迭�� �޾�
	//��ձ���, ��պ��� ���� �ֵ� ī��Ʈ�� 
	//ī��Ʈ�� ������ �л���*100 = ���侲
	
	
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