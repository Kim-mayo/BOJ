#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int>q;
vector<int>visited;
int N, K;
void BFS(int V) {

	q.push(V);
	
	visited[V] = 0;
	while (!q.empty()) {



		int fr = q.front();
		if (fr == K) {
			cout << visited[fr];
			return;
		}
		q.pop();
		
		int plus = fr + 1;
		int minus = fr - 1;
		int mul = fr * 2;

		if (plus <=2*K&&visited[plus] == -1) { 
			visited[plus] = visited[fr] + 1;
			q.push(plus); 
		}
		if (minus>=0&&visited[minus] == -1) { 
			visited[minus] = visited[fr] + 1;
			q.push(minus);	
		}
		if (mul<=2*K&&visited[mul] == -1) { 
			visited[mul] = visited[fr] + 1;
			q.push(mul); 
		}

			
		

	}

}
int main() {

	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	visited.resize(200001,-1);
	BFS(N);

}