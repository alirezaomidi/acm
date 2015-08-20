#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;

const int inf = 1e9;

// map<ll, ll> mp;
// long mp[1];
ll maxx;

ll ack(ll n) {
	// if (mp[n])
	// 	return mp[n];
	if (n == 1)
		return 1;
	if (n % 2 == 0)
		// return mp[n] = 1 + ack(n / 2);
		return 1 + ack(n / 2);
	// return mp[n] = 1 + ack(3 * n + 1);
	return 1 + ack(3 * n + 1);
}

int main() {
	ios::sync_with_stdio(false);

	// mp[1] = 1;
	ll l, h;
	while (cin >> l >> h) {
		if (!l && !h)
			break;
		maxx = 0;
		if (h < l) {
			ll tmp = h;
			h = l;
			l = tmp;
		}
		int ans = l;
		for (ll i = l; i <= h; i++) {
			ll cur;
			if (i == 1) {
				ans = 1;
				cur = 4;
			} else
				cur = ack(i);
			// cerr << i << ' ' << cur << endl;
			if (cur > maxx) {
				maxx = cur;
				ans = i;
			}
		}
		cout << "Between " << l << " and " << h << ", " << ans << " generates the longest sequence of " << maxx - 1 << " values." << endl;
	}

	return 0;
}
