#include <iostream>
using namespace std;
char s[1000001];
int check[26];

int main() {
	//�ϴ� �ܾ� ���ڿ��� �޾ƿ���.
	//�ҹ���->�빮�ڷ� �ٲ㼭 ī���ý�
	//üũ���ĺ� �迭���� ��ĭ�� ī����
	//����ū�� ���ִ°� ã�Ƽ� �빮�ڷ� ���
	//���� ����ū������������ ?���
	int cnt = 1;
	cin >> s;
	for (int i = 0; s[i] != '\0'; i++) {
		
		//�ҹ��ڸ�? üũ[s[i]-'a']
		//�빮�ڸ�? �빮�ڸ� s[i]-'A' �̰ɾ��� ��������..
		//s[i]-a <0 �� �ҹ��ڶ�°�..?

		if ('a' <= s[i] && s[i] <= 'z') {
			check[s[i] - 'a'] += cnt;
		}
		else {
			check[s[i] - 'A'] += cnt;
		}

	}

	int b = -1000000;
	int index = 0;
	for (int i = 0; i < 26; i++) {
		if (b < check[i]) {
			b = check[i];
			index = i;
		}
		
	}
	int q = 0;
	for (int i = 0; i < 26; i++) {
		if (check[i] == b) q++;

	}
	if (q == 1) cout << (char)(index + 'A');
	else cout << "?";
}