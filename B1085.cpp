#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

	pair<int,int> arr[2];
	int  x, y, w, h; cin >> x >> y >> w >> h;
	
	int disx = min(x, abs(x - w));
	int disy = min(y, abs(y - h));
	int dis = sqrt(pow(x - w, 2) + pow(y - h, 2));
	int disxy = min(disx, disy);

	cout << min(disxy, dis);
}