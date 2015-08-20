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

const int inf = 1e9;

int intlen(ll n) {
	int len = 0;
	while (n > 0) {
		n /= 10;
		len++;
	}
	return len;
}

bool notrepeated(ll n) {
	bool digits[10] = {false};
	while (n > 0) {
		if (digits[n % 10])
			return false;
		digits[n % 10] = true;
		n /= 10;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	bool first = true;
	while (t--) {
		ll n; cin >> n;
		if (!first)
			cout << endl;
		else
			first = false;
		for (ll i = 1; intlen(n * i) <= 10; i++) {
			if (notrepeated(n * i) && notrepeated(i))
				cout << n * i << " / " << i << " = " << n << endl;
		}
	}

	return 0;
}
