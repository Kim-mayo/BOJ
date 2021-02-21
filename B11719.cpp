#include <iostream>
#include <string>
using namespace std;

int main() {

	while (1) {
		string a; 
		getline(cin, a);
		if (cin.eof())break;
		cout << a << "\n";
	}

}