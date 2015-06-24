#include <iostream>
#include <cmath>
#include <deque>
using namespace std;

int get_divisors_count(int n) {
	int res = 1, count = 1;
	int sqr = sqrt(n);
	for (int i = 2; i <= sqr; i = (i == 2 ? 3 : i + 2)) {
		int pow = 0;
		while(n % i == 0) {
		    pow++;
		    n /= i;
		}
		if (pow > 0) {
			count *= pow + 1;
			sqr = sqrt(n);
		}
	}
	if (n > 1)
		count *= 2;
	return count;
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		int l, u; cin >> l >> u;
		int _max = 0, tmp, num;
		for (int i = l; i <= u; i++)
			if ((tmp = get_divisors_count(i)) > _max) {
				_max = tmp;
				num = i;
			}
		cout << "Between " << l << " and " << u << ", " << num << " has a maximum of " << _max << " divisors." << endl;
	}

	return 0;
}