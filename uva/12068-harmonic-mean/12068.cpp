#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

const int inf = 1e9;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	ios::sync_with_stdio(false);

	int ts; cin >> ts;
	for (int t = 1; t <= ts; t++) {
		int n; cin >> n;
		vii v(n, ii(1, 0));
		ll den = 1;
		for (int i = 0; i < n; i++) {
			cin >> v[i].second;
			den *= v[i].second;
		}
		ll num = 0;
		for (int i = 0; i < n; i++) {
			v[i].first = den / v[i].second;
			num += v[i].first;
		}
		den *= n;
		ll g = gcd(num, den);
		cout << "Case " << t << ": " << den / g << '/' << num / g << endl;
	}

	return 0;
}
