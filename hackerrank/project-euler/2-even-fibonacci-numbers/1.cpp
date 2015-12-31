#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

const int inf = 1e9;

vi fibseq;

ll fib(int n) {
	if (n < fibseq.size())
		return fibseq[n];
	if (n < 2)
		return n + 1;
	fibseq.push_back(fib(n - 2) + fib(n - 1));
	return fibseq[n];
}

int main() {
	ios::sync_with_stdio(false);

	fibseq.push_back(1);
	fibseq.push_back(2);

	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		ll ans = 0;
		for (int i = 0; fib(i) < n; i++)
			if (fib(i) % 2 == 0)
				ans += fib(i);
		cout << ans << endl;
	}

	return 0;
}
