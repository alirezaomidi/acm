#include <iostream>
#include <string>
using namespace std;

int decimal(string n, int b) {
	int res = 0;
	for (int i = n.length() - 1, pow = 1; i >= 0; --i, pow *= b) {
		int digit;
		if ('0' <= n[i] && n[i] <= '9')
			digit = n[i] - '0';
		else
			digit = n[i] - 'A' + 10;
		if (digit >= b)
			return -1;
		res += digit * pow;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);

	string a, b;
	while (cin >> a >> b) {
		bool found = false;
		for (int i = 2; i <= 36; ++i) {
			for (int j = 2; j <= 36; ++j) {
				int deca = decimal(a, i), decb = decimal(b, j);
				if (deca != -1 && decb != -1 && deca == decb) {
					found = true;
					cout << a << " (base " << i << ") = " << b << " (base " << j << ')' << endl;
					break;
				}
			}
			if (found) break;
		}
		if (!found)
			cout << a << " is not equal to " << b << " in any base 2..36" << endl;
	}

	return 0;
}