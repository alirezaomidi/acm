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
typedef vector<vvi> vvvi;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

const int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	int it = 0;
	while (t--) {
		it++;
		int m, n; cin >> m >> n;
		int k; cin >> k;
		vvi v(m, vi(n, 0));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> v[i][j];

		queue<iii> q;
		vvvi dist(m, vvi(n, vi(k + 1, inf)));
		q.push(iii(k, ii(0, 0)));
		dist[0][0][k] = 0;

		vii neighbors;
		neighbors.push_back(ii(0, 1));
		neighbors.push_back(ii(0, -1));
		neighbors.push_back(ii(1, 0));
		neighbors.push_back(ii(-1, 0));

		while (!q.empty()) {
			iii cur = q.front();
			q.pop();
			for (int i = 0; i < neighbors.size(); i++) {
				ii nei = ii(cur.second.first + neighbors[i].first, cur.second.second + neighbors[i].second);
				if (nei.first >= 0 && nei.first < m && nei.second >= 0 && nei.second < n) {
					int tur = k;
					if (v[nei.first][nei.second] == 1)
						tur = cur.first - 1;

					if (dist[nei.first][nei.second][tur] == inf) {
						dist[nei.first][nei.second][tur] = dist[cur.second.first][cur.second.second][cur.first] + 1;
						q.push(iii(tur, nei));
					}
				}
			}
		}

		int ans = inf;
		for (int i = 0; i <= k; i++) {
			ans = min(ans, dist[m - 1][n - 1][i]);
		}


		// if (it == 922) {
		// 		cerr << "k " << k << endl;
		// 		for (int i = 0; i < m; i++) {
		// 			for (int j = 0; j < n; j++)
		// 				cerr << v[i][j] << ' ';
		// 			cerr << endl;
		// 		}
		// 		for (int i = 0; i < m; i++) {
		// 			for (int j = 0; j < n; j++)
		// 				cerr << dist[i][j] << ' ';
		// 			cerr << endl;
		// 		}
		// 	}

		if (ans < inf)
			cout << ans << endl;
		else
			cout << -1 << endl;
	}

	return 0;
}
