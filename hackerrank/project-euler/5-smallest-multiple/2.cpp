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

ll gcd(ll a, ll b) {
	if (!b)
		return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll ans = 1;
		for (int i = 2; i <= n; i++)
			ans = ans * i / gcd(ans, i);
		cout << ans << endl;
	}

	return 0;
}
