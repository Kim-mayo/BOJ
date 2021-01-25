#include <iostream>
#include <vector>
using namespace std;

int tree[26][2];

void Pre(int me) {//ÀüÀ§ -> ³ª ¿Þ ¿À

	cout << char(me + 'A');
	if (tree[me][0] != -1) Pre(tree[me][0]);
	if (tree[me][1] != -1) Pre(tree[me][1]);

	return;
}
void In(int me) {//ÁßÀ§ -> ¿Þ ³ª ¿À

	if (tree[me][0] != -1) In(tree[me][0]);
	cout << char(me + 'A');
	if (tree[me][1] != -1) In(tree[me][1]);

	return;
}
void Post(int me) {//ÈÄÀ§ -> ¿Þ ¿À ³ª

	if (tree[me][0] != -1) Post(tree[me][0]);
	if (tree[me][1] != -1) Post(tree[me][1]);
	cout << char(me + 'A');

	return;
}

int main() {

	int N; cin >> N;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 2; j++) {
			tree[i][j] = -1;
		}
	}
	for (int i = 0; i < N; i++) {
		char me, left, right;
		cin >> me >> left >> right;
		if(left!='.') tree[me - 'A'][0] = left - 'A';
		if(right!='.')tree[me - 'A'][1] = right - 'A';
	}

	Pre(0);
	cout << "\n";
	In(0);
	cout << "\n";
	Post(0);

	return 0;
}