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
const int MAX = 101;

int main() {
	ios::sync_with_stdio(false);

	viii neigh;
	neigh.push_back(iii(-1, ii(0, 0)));
	neigh.push_back(iii(1, ii(0, 0)));
	neigh.push_back(iii(0, ii(-1, 0)));
	neigh.push_back(iii(0, ii(1, 0)));
	neigh.push_back(iii(0, ii(0, -1)));
	neigh.push_back(iii(0, ii(0, 1)));

	int t; cin >> t;
	while (t--) {
		int m; cin >> m;
		vector<vvi> v(MAX + 1, vvi(MAX + 1, vi(MAX + 1, 0)));
		vector<vvi> visited(MAX + 1, vvi(MAX + 1, vi(MAX + 1, 0)));
		int ans = 0;
		for (int i = 0; i < m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			v[x][y][z] = 1;
		}
		for (int i = 1; i < MAX; i++)
			for (int j = 1; j < MAX; j++)
				for (int k = 1; k < MAX; k++)
					if (!v[i][j][k] && !visited[i][j][k]) {
						// cerr << i << ' ' << j << ' ' << k << endl;
						// dfs
						stack<iii> s;
						s.push(iii(i, ii(j, k)));
						visited[i][j][k] = 1;
						bool found_hole = true;
						int count = 0;
						while (!s.empty()) {
							iii p = s.top();
							s.pop();
							count++;
							// cerr << p.first << ' ' << p.second.first << ' ' << p.second.second << endl;
							if (p.first == 0 || p.first == MAX || p.second.first == 0 || p.second.first == MAX || p.second.second == 0 || p.second.second == MAX) {
								found_hole = false;
								// cerr << i << ' ' << j << ' ' << k << endl;
								// cerr << p.first << ' ' << p.second.first << ' ' << p.second.second << endl;
								continue;
							}
							for (int nei = 0; nei < 6; nei++) {
								int a = p.first + neigh[nei].first;
								int b = p.second.first + neigh[nei].second.first;
								int c = p.second.second + neigh[nei].second.second;
								if (a >= 0 && a <= MAX && b >= 0 && b <= MAX && c >= 0 && c <= MAX && !v[a][b][c] && !visited[a][b][c]) {
									if (a > 0 && a < MAX && b > 0 && b < MAX && c > 0 && c < MAX)
										visited[a][b][c] = 1;
									s.push(iii(a, ii(b, c)));
								}
							}
						}
						if (found_hole) {
							ans++;
						}
					}
		cout << ans << endl;
	}

	return 0;
}
