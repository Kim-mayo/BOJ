#include <iostream>
using namespace std;

int heap[1000001]; 
int hsize = 0;
void Insert(int a) {

	hsize++;

	heap[hsize] = a;
	int curr = hsize;
	while (true) {

		if (curr == 1) {
			break;
		}
		else if (heap[curr] > heap[curr / 2]) {
			int tmp = heap[curr];
			heap[curr] = heap[curr / 2];
			heap[curr / 2] = tmp;
			curr = curr / 2;
		}
		else break;
	}
}

int Remove() {

	int del = heap[1];
	heap[1] = heap[hsize];
	hsize--;

	int curr = 1;

	while (1) {

		int left = curr * 2;
		int right = curr * 2 + 1;

		if (left > hsize) {//자식없을때
			break;
		}
		else if (right > hsize) {//자식하나왼쪽자식
			if (heap[curr] < heap[left]) {
				int tmp = heap[curr];
				heap[curr] = heap[left];
				heap[left] = tmp;

				curr = left;
			}
			else break;
		}
		else {//자식둘

			if (heap[left] > heap[right]) {
				if (heap[left] > heap[curr]) {
					int tmp = heap[curr];
					heap[curr] = heap[left];
					heap[left] = tmp;

					curr = left;
				}
				else break;
			}
			else {
				if (heap[right] > heap[curr]) {
					int tmp = heap[curr];
					heap[curr] = heap[right];
					heap[right] = tmp;

					curr = right;
				}
				else break;
			}
		}

	}
	return del;
}

int main() {

	int N; cin >> N;

	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		Insert(-a);
	}

	for (int i = 0; i < N; i++) {
		cout << -Remove() << "\n";
	}


}