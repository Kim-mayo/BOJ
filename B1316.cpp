#include <iostream>
#include <cstring>
using namespace std;

char sen[101];
int main() {

	int N; cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int group = 0;
		cin >> sen;
		int len = strlen(sen);
		for (int j = 0; j < len; j++) {
			//���ӵǾ��־�ǰ�, �ȵ��־��
			//������ ���ɰھ�.....!
			while(sen[j] == sen[j + 1]&&(j+1)<len) {
				j++;
			}
			for (int k = j + 1; k < len; k++) {
				if (sen[j] == sen[k]) group=-1;
			}

		}
		
		if (group == 0) cnt++;


	}

	cout << cnt;


}