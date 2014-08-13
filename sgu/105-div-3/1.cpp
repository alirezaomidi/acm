#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	n % 3 == 1 || n % 3 == 0 ? cout << n / 3 * 2 << endl : cout << n / 3 * 2 + 1 << endl;

	return 0;
}
