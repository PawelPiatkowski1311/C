#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main() {
	list <int> nieposortowane = {9,1,8,2,7,3,6,4,5,0};
	list <int> posortowane;
	posortowane.push_back(nieposortowane.back());
	nieposortowane.pop_back();
	auto temp = posortowane.begin();
	while (!nieposortowane.empty()) {
		for (int i = 0; nieposortowane.back() <= *temp || i < 10; i++) {
			advance(temp, i);
			*temp = nieposortowane.back();
		}
	}
}