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

void topSort(vi &order, int v, vi &vis, vvi &graph) {
  vis[v] = 1;
  for(auto &e : graph[v])
		if(!vis[e])
			topSort(order, e, vis, graph);
  order.push_back(v);
}

int main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	cin.get();
	cin.get();

	while (t--) {
		vvi graph(26, vi());
		vi days(26, 0), order, vis(26, 1), dis(26, 0);

		string tmp;
		int source = 0;
		while (getline(cin, tmp)) {
			if (tmp.empty())
				break;
			stringstream ss;
			ss << tmp;
			char c; ss >> c;
			vis[c - 'A'] = 0;
			ss >> days[c - 'A'];
			tmp.clear();
			ss >> tmp;
			if (tmp.empty())
				source = c - 'A';
			for (int i = 0; i < tmp.size(); i++)
				graph[tmp[i] - 'A'].push_back(c - 'A');
		}

		dis[source] = days[source];
		for(int i = 0; i < 26; i++)
			if(!vis[i])
				topSort(order, i, vis, graph);

		for(int i = order.size() - 1; i >= 0; i--)
			for(auto &e : graph[order[i]])
				dis[e] = max(dis[e], dis[order[i]] + days[e]);

		int ans = 0;
		for (int i = order.size() - 1; i >= 0; i--)
			ans = max(ans, dis[order[i]]);
		cout << ans << endl;
		if (t > 0)
			cout << endl;
	}

	return 0;
}
