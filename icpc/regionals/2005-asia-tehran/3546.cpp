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
typedef pair<double, double> dd;

const int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		string ans;
		ans += (char)k + '0';
		int carry = 0;
		while (true) {
			int d = n * (ans[ans.size() - 1] - '0') + carry;
			carry = d / 10;
			d %= 10;
			if (d == k && carry == 0) {
				break;
			}
			ans += (char)d + '0';
		}
		reverse(ans.begin(), ans.end());
		if (ans[0] == '0') {
			cout << 0 << endl;
		} else {
			cout << ans << endl;
		}
	}

	return 0;
}
