#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
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

ll fact(int n) {
	ll res = 1;
	for (int i = 2; i <= n; i++)
		res *= i;
	return res;
}

ll powll(int b, int p) {
	ll res = 1;
	for (int i = 0; i < p; i++)
		res *= b;
	return res;
}

int main() {
	ios::sync_with_stdio(false);

	int n;
	while (cin >> n && n) {
		map<int, int> freq;
		for (int i = 0; i < n; i++) {
			int digit; cin >> digit;
			freq[digit]++;
		}
		ll nums_fact = 1;
		for (int i = 0; i < 10; i++)
			if (freq[i])
				nums_fact *= fact(freq[i]);
		ll perms = fact(n) / nums_fact;

		ll sum = 0;
		for (int i = 0; i < 10; i++) {
			ll share = (double)perms / n * freq[i];
			sum += share * i;
		}
		
		ll ans = 0;
		for (int i = 0; i < n; i++)
			ans += sum * powll(10, i);

		cout << ans << endl;
	}

	return 0;
}
