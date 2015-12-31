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

vi primes;

bool is_prime(int n) {
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	int sqr = sqrt(n) + 1;
	for (int i = 0; primes[i] <= sqr && i < primes.size(); i++)
		if (n % primes[i] == 0)
			return false;
	return true;
}

int get_prime(int n) {
	if (n < primes.size())
		return primes[n];
	int p = 2;
	if (primes.size() > 0)
		p = primes.back() + 1;
	while (n >= primes.size()) {
		if (is_prime(p))
			primes.push_back(p);
		p++;
	}
	return primes[n];
}

int main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << get_prime(n - 1) << endl;
	}

	return 0;
}
