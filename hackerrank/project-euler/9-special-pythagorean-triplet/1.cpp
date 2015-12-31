/*
   a^2 + b^2 = c^2
&  b = n - a - c
-> (2)a^2 - (2(n-c))a + ((n-c)^2 - c^2) = 0
-> a = 2(n-c) +- sqrt((2(n-c))^2 - 4*2*(n-c)^2 - c^2
*/

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
		int ans = -1;
		for (int c = 1; c < n; c++) {
			double delta = pow(2 * (n - c), 2) - 8 * (pow(n - c, 2) - c * c);
			if (sqrt(delta) == (int)sqrt(delta)) {
				double a1 = (2 * (n - c) + sqrt(delta)) / 4;
				double a2 = (2 * (n - c) - sqrt(delta)) / 4;
				if (a1 == (int)a1) {
					int b = n - c - a1;
					if (a1 > 1 && b > 1)
						ans = max(ans, (int)a1 * b * c);
				} else if (a2 == (int)a2) {
					int b = n - c - a2;
					if (a2 > 1 && b > 1)
						ans = max(ans, (int)a2 * b * c);
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}
