#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if (x == y) {
			for (int i = 0, a = 0; i < x; ++i) {
				if (i % 2 == 0)
					a++;
				else
					a += 3;
			}
			cout << a << endl;
		} else if (x - y == 2) {
			for (int i = 0, a = 0; i < y; ++i) {
				if (i % 2 == 0)
					a++;
				else
					a += 3;
			}
			cout << a << endl;
		} else {
			cout << "No Number" << endl;
		}
	}

	return 0;
}