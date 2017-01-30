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

int main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int, int> index;
		int ans = 0, cur = 0, last = 0;
		for (int i = 1; i <= n; i++) {
			int snowflake; cin >> snowflake;
			if (index[snowflake]) {
				last = max(last, index[snowflake]);
				cur = i - last;
			} else
				cur++;
			ans = max(ans, cur);
			index[snowflake] = i;
		}
		cout << ans << endl;
	}

	return 0;
}
