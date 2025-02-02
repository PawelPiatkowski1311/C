#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack <int> stos1;
	stack <int> stos2;
	stack <int> stos3;
	for (int i = 4; i > 0; i--) stos1.push(i);
	cout << "stosy:\n";
	cout << "stos 1\n";
	cout << stos1.top() << " ";
	for (int i = 0; i < stos1.size(); i++) {
	}
	cout << "stos 2\n";
	cout << "stos 3\n";

}