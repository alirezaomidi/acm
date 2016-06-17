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
const int MAX = 20;
const int LEN = 4;

int main() {
	ios::sync_with_stdio(false);

	vvi grid(MAX, vi(MAX, 0));
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cin >> grid[i][j];

	int ans = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			// below
			if (i <= MAX - LEN) {
				int cur = 1;
				for (int k = 0; k < LEN; k++)
					cur *= grid[i + k][j];
				ans = max(ans, cur);
			}
			// front
			if (j <= MAX - LEN) {
				int cur = 1;
				for (int k = 0; k < LEN; k++)
					cur *= grid[i][j + k];
				ans = max(ans, cur);
			}
			// diagonal : NW to SE
			if (i <= MAX - LEN && j <= MAX - LEN) {
				int cur = 1;
				for (int k = 0; k < LEN; k++)
					cur *= grid[i + k][j + k];
				ans = max(ans, cur);
			}
			// diagonal : NE to SW
			if (i <= MAX - LEN && j >= LEN - 1) {
				int cur = 1;
				for (int k = 0; k < LEN; k++)
					cur *= grid[i + k][j - k];
				ans = max(ans, cur);
			}
		}
	}

	cout << ans << endl;

	return 0;
}
