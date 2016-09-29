#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

const int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);

	int ts; cin >> ts;
	for (int test = 1; test <= ts; test++) {
		double k; cin >> k;
		double tax = 0;
		if (k > 18e4) {
			k -= 18e4;
		} else {
			k = 0;
		}

		if (k > 3e5) {
			k -= 3e5;
			tax += 3e4;
		} else {
			tax += .1 * k;
			k = 0;
		}

		if (k > 4e5) {
			k -= 4e5;
			tax += 1.5 * 4e4;
		} else {
			tax += .15 * k;
			k = 0;
		}

		if (k > 3e5) {
			k -= 3e5;
			tax += 2 * 3e4;
		} else {
			tax += .2 * k;
			k = 0;
		}

		tax += .25 * k;

		if (tax > 0 && tax < 2e3)
			tax = 2e3;

		cout << "Case " << test << ": " << (int)ceil(tax) << endl;
	}

	return 0;
}
