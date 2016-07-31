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

	int n; cin >> n;
	for (int t = 1; t <= n; t++) {
		int k; cin >> k;
		int a = 0, b = 0, c = 0, d = 0;
		for (int i = 2; i < k / 2; i++) {
			if (k % i == 0) {
				if (a == 0) {
					a = i;
					b = k / i;
				} else {
					c = i;
					d = k / i;
					break;
				}
			}
		}
		printf("Case #%d: %d = %d * %d = %d * %d\n", t, k, a, b, c, d);
	}

	return 0;
}
