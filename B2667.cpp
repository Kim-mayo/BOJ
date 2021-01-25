#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string map[25];
bool visited[25][25];
int n;
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
vector <vector <int> >group_numbering (25,vector<int>(25,0));
vector <int> groupN;
int DFS(int x, int y,int group) {
	if (visited[x][y] == true) return 0;
	visited[x][y] = true; 
	int cnt = 1;
	group_numbering[x][y] = group;
	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];

		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (map[nx][ny] == '1' && visited[nx][ny] == false) {

				cnt+=DFS(nx, ny,group);
				
			}
		}
	}
	return cnt;
}

int main(){
	cin >> n;
	int group = 1;
	for (int i = 0;i < n; i++) {//n
		cin >> map[i];
	}
	int g;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1' && visited[i][j] == false) {
				
				g=DFS(i, j, group);
				groupN.push_back(g);
				group++;
			}			
		}
	}
	//�׷�ѹ����� ���ٸ� �׷�N�� ����...n^2

	//groupN.resize(group);
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		groupN[group_numbering[i][j]]++;				
	//	}
	//} ��Ʈ�����̾�



	sort(groupN.begin(), groupN.end());

	cout << group-1 << "\n";
	for (int i = 0; i < groupN.size(); i++) {
		cout << groupN[i] << "\n";
	}
	
}//10ĭ 0~9��� �η�Ÿ���� ������� ���� ���� �غ���
//10^10 