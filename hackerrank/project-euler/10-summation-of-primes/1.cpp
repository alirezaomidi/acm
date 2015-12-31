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

ll sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
	sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= sieve_size; i++)
		if (bs[i]) {
			for (ll j = i * i; j <= sieve_size; j += i) bs[j] = 0;
			primes.push_back(i);
		}
}

int main() {
	ios::sync_with_stdio(false);

	sieve(1e6);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll ans = 0;
		for (int i = 0; primes[i] <= n; i++)
			ans += primes[i];
		cout << ans << endl;
	}

	return 0;
}
