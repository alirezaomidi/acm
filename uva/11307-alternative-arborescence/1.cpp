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

int str2int(string s) {
	stringstream ss;
	ss << s;
	int n;
	ss >> n;
	return n;
}

vvi g, memo;

int solve(int n, int color) {
	if (memo[n][color] != inf)
		return memo[n][color];
	memo[n][color] = color;
	for (int i = 0; i < g[n].size(); i++) {
		int v = g[n][i];
		int cur_min = inf;
		for (int j = 1; j <= 6; j++)
			if (j != color)
				cur_min = min(cur_min, solve(v, j));
		memo[n][color] += cur_min;
	}
	return memo[n][color];
}

int main() {
	ios::sync_with_stdio(false);

	int n;
	while (cin >> n && n) {
		g.clear();
		g.resize(n, vi());
		vi parent(n, -1);

		string s;
		cin.get();
		while(getline(cin, s)) {
			if (s.empty())
				break;
			stringstream ss;
			string tmp;
			ss << s;
			ss >> tmp;
			int u = str2int(tmp.substr(0, tmp.size() - 1));
			int v;
			// cerr << u << endl;

			while (ss >> v) {
				g[u].push_back(v);
				parent[v] = u;
				// cerr << v << ' ';
			}
		}

		memo.clear();
		memo.resize(n, vi(7, inf));

		int root = 0;
		while (parent[root] != -1)
			root = parent[root];

		int ans = inf;
		for (int color = 1; color <= 6; color++)
			ans = min(ans, solve(root, color));
		cout << ans << endl;
	}

	return 0;
}
