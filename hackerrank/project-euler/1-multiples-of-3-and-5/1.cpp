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

ll sum(ll n, int base) {
	n /= base;
	return (n * (n + 1)) / 2 * base;
}

int main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		n--;
		cout << sum(n, 3) + sum(n, 5) - sum(n, 15) << endl;
	}

	return 0;
}
