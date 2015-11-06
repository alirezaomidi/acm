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

	map<string, int> mp;

	int t; cin >> t;
	while (t--) {
		int r, c; cin >> r >> c;
		vvi v(r, vi(c, 0));
		ii s; cin >> s.first >> s.second;
		s.first--;
		s.second--;
		string dir_s; cin >> dir_s;
		ii dir;
		if (dir_s == "DR")
			dir = ii(1, 1);
		else if (dir_s == "DL")
			dir = ii(1, -1);
		else if (dir_s == "UR")
			dir = ii(-1, 1);
		else
			dir = ii(-1, -1);

		int ans = 0;

		vector<iii> prev;
		prev.push_back(iii(dir.second/dir.first, s));

		ii p = s;
		v[p.first][p.second] = 1;
		while (true) {
			p.first += dir.first;
			p.second += dir.second;
			if (p.first == 0 && p.second == 0 || p.first == 0 && p.second == c - 1 || p.first == r - 1 && p.second == 0 || p.first == r - 1 && p.second == c - 1) {
				break;
			}
			if (p.first == 0 || p.first == r - 1 || p.second == 0 || p.second == c - 1) {
				bool ok = true;
				for (int i = 0; i < prev.size(); i++) {
					if (prev[i].second == p) {
						if (prev[i].first == -1 * (dir.second / dir.first)) {
							ok = false;
							ans++;
							break;
						}
					}
				}
				if (!ok) {
					break;
				}

				prev.push_back(iii(-1 * dir.second / dir.first, p));
				if (p.first == 0 || p.first == r - 1) {
					dir.first == 1 ? dir.first = -1 : dir.first = 1;
				} else {
					dir.second == 1 ? dir.second = -1 : dir.second = 1;
				}

			}
			if (v[p.first][p.second])
				ans++;
			v[p.first][p.second] = 1;
		}
		cout << ans << endl;

	}

	return 0;
}
