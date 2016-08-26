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

	vector<ii> neighs;
	neighs.push_back(ii(0, 1));
	neighs.push_back(ii(0, -1));
	neighs.push_back(ii(1, 0));
	neighs.push_back(ii(-1, 0));

	int w, h, tst = 1;
	while (cin >> w >> h && w && h) {
		vector<string> v(h, "");
		for (int i = 0; i < h; i++)
			cin >> v[i];

		vvi cc(h, vi(w, 0));
		int curcc = 0;
		int indice = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				// cerr << i << ' ' << j << endl;
				if ((v[i][j] == '*' || v[i][j] == 'X') && !cc[i][j]) {
					curcc++;
					// cerr << "dfs" << endl;
					stack<ii> s;
					s.push(ii(i, j));
					cc[i][j] = curcc;
					while (!s.empty()) {
						ii vertex = s.top();
						s.pop();
						// cerr << vertex.first << ' ' << vertex.second << endl;
						// cerr << "indfs" << endl;
						for (int k = 0; k < neighs.size(); k++) {
							ii neigh = ii(vertex.first + neighs[k].first, vertex.second + neighs[k].second);
							if (neigh.first < 0 || neigh.first >= h || neigh.second < 0 || neigh.second >= w)
								continue;
							if ((v[neigh.first][neigh.second] == '*' || v[neigh.first][neigh.second] == 'X') && !cc[neigh.first][neigh.second]) {
								s.push(neigh);
								cc[neigh.first][neigh.second] = curcc;
							}
						}
					}
				}
			}

		map<int, int> dice;
		vvi visited(h, vi(w, 0));
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				if (v[i][j] == 'X' && !visited[i][j]) {
					dice[cc[i][j]]++;
					stack<ii> s;
					s.push(ii(i, j));
					visited[i][j] = 1;
					while (!s.empty()) {
						ii vertex = s.top();
						s.pop();
						for (int k = 0; k < neighs.size(); k++) {
							ii neigh = ii(vertex.first + neighs[k].first, vertex.second + neighs[k].second);
							if (neigh.first < 0 || neigh.first >= h || neigh.second < 0 || neigh.second >= w)
								continue;
							if (v[neigh.first][neigh.second] == 'X' && !visited[neigh.first][neigh.second]) {
								s.push(neigh);
								visited[neigh.first][neigh.second] = 1;
							}
						}
					}
				}
				visited[i][j] = 1;
			}

		cout << "Throw " << tst << endl;
		vi ans;
		for (int i = 1; i <= curcc; i++)
			ans.push_back(dice[i]);
		sort(ans.begin(), ans.end());
		// cerr << curcc << ' ' << ans.size() << endl;
		cout << ans[0];
		for (int i = 1; i < curcc; i++)
			cout << ' ' << ans[i];
		cout << endl << endl;
		tst++;
	}

	return 0;
}
