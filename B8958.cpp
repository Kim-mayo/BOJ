#include <iostream>
using namespace std;
char quiz[80];
int main() {

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		int sum = 0;
		int s = 0;
		//�������� X�� �氪 �ʱ�ȭ. ��÷�� O��1,X��0
		cin >> quiz;

		if (quiz[0] == 'X') sum = 0;
		else  sum = 1;
		s = sum;
		for (int j = 1; quiz[j] != '\0'; j++) {
			if (quiz[j - 1] == 'O' && quiz[j] == 'O') sum += 1;
			else if (quiz[j - 1] == 'O' && quiz[j] == 'X')sum = 0;
			else if (quiz[j - 1] == 'X' && quiz[j] == 'O')sum += 1;
			else if (quiz[j - 1] == 'X' && quiz[j] == 'X')sum = 0;
			
			s += sum;
		}

		cout << s << "\n";
	}

}