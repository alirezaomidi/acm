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
typedef vector<ll> vi;
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

	int tst; cin >> tst;
	for (int t = 1; t <= tst; t++) {
		int n, m, budget; cin >> n >> m >> budget;
		vvi v(n, vi(m, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> v[i][j];
				if (i > 0) v[i][j] += v[i - 1][j];
				if (j > 0) v[i][j] += v[i][j - 1];
				if (i > 0 && j > 0) v[i][j] -= v[i - 1][j - 1];
			}

		ll cost = 100 * 100 * 1e6;
		int surface = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int k = i; k < n; k++)
					for (int l = j; l < m; l++) {
						ll rect_cost = v[k][l];
						int rect_surface = (k - i + 1) * (l - j + 1);
						if (i > 0) rect_cost -= v[i - 1][l];
						if (j > 0) rect_cost -= v[k][j - 1];
						if (i > 0 && j > 0) rect_cost += v[i - 1][j - 1];
						if (rect_cost > budget)
							break;
						if (rect_surface > surface) {
							surface = rect_surface;
							cost = rect_cost;
						} else if (rect_surface == surface) {
							if (rect_cost < cost)
								cost = rect_cost;
						}
					}

		if (surface == 0)
			cost = 0;
		cout << "Case #" << t << ": " << surface << ' ' << cost << endl;
	}

	return 0;
}
