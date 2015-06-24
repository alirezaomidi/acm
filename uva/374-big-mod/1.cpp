#include <iostream>
using namespace std;

int pow2(int n) {
	return n * n;
}

int solve(int b, int p, int m) {
	if (p == 0) return 1;
	if (p % 2 == 0) return (pow2(solve(b, p / 2, m) % m)) % m;
	else return ((b % m) * (solve(b, p - 1, m))) % m;
}

int main() {
	int b, p, m;
	while (cin >> b >> p >> m)
		cout << solve(b % m, p, m) << endl;

	return 0;
}
