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
		int n; cin >> n;
		vvi v(2 * n, vi(2 * n, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
				v[i + n][j] = v[i][j + n] = v[i + n][j + n] = v[i][j];
			}

		n = 2 * n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (i > 0) v[i][j] += v[i - 1][j];
				if (j > 0) v[i][j] += v[i][j - 1];
				if (i > 0 && j > 0) v[i][j] -= v[i - 1][j - 1];
			}

		int ans = -100 * 150 * 150;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = i; k < n && k - i < n / 2; k++)
					for (int l = j; l < n && l - j < n / 2; l++) {
						int rect = v[k][l];
						if (i > 0) rect -= v[i - 1][l];
						if (j > 0) rect -= v[k][j - 1];
						if (i > 0 && j > 0) rect += v[i - 1][j - 1];
						ans = max(ans, rect);
					}
		cout << ans << endl;

	}

	return 0;
}
