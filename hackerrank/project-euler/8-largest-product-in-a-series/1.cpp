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
		int n, k; cin >> n >> k;
		string num; cin >> num;
		int ans = 0;
		for (int i = 0; i < n - k; i++) {
			int sum = 1;
			for (int j = 0; j < k; j++)
				sum *= (num[i + j] - '0');
			ans = max(ans, sum);
		}
		cout << ans << endl;
	}

	return 0;
}
