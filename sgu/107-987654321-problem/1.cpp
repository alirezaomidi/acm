/* n * n % 1000000000 must be 987654321
 * compute for n < 1000000000
 * there is 8 results:
 * 111111111
 * 119357639
 * 380642361
 * 388888889
 * 611111111
 * 619357639
 * 880642361
 * 888888889 */

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n < 9)
		cout << 0;
	else if (n == 9)
		cout << 8;
	else {
		cout << 72;
		n -= 10;
		for (int i = 0; i < n; ++i)
			cout << 0;
	}
	cout << endl;

	return 0;
}
