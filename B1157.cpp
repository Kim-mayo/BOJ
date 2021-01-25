#include <iostream>
using namespace std;
char s[1000001];
int check[26];

int main() {
	//일단 단어 문자열로 받아오기.
	//소문자->대문자로 바꿔서 카운팅스
	//체크알파벳 배열만들어서 그칸에 카운팅
	//제일큰수 들어가있는거 찾아서 대문자로 출력
	//만약 제일큰수가여러개면 ?출력
	int cnt = 1;
	cin >> s;
	for (int i = 0; s[i] != '\0'; i++) {
		
		//소문자면? 체크[s[i]-'a']
		//대문자면? 대문자면 s[i]-'A' 이걸어케 구분하지..
		//s[i]-a <0 면 소문자라는거..?

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