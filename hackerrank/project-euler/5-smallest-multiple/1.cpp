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

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vi pows(n + 1, 0);
		for (int i = 2; i <= n; i++) {
			int tmp = i;
			for (int j = 2; tmp > 1; j++) {
				int p = 0;
				while (tmp % j == 0) {
					tmp /= j;
					p++;
				}
				if (p)
					pows[j] = max(pows[j], p);
			}
		}

		ll ans = 1;
		for (int i = 2; i <= n; i++)
			if (pows[i])
				ans *= pow(i, pows[i]);
		cout << ans << endl;
	}

	return 0;
}
