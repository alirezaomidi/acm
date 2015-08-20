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

const int inf = 1e9;

int neigh[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool comp(ii a, ii b) {
	if (a.second > b.second)
		return true;
	if (a.second < b.second)
		return false;
	if (a.first < b.first)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	int counter = 1;
	while (t--) {
		int h, w; cin >> h >> w;
		if (h == 0 || w == 0) {
			cout << "World #" << counter << endl;
			counter++;
			continue;
		}
		vector<string> v(h, "");
		vvi table(h, vi(w, 0));
		vii langs(26, ii(0, 0));
		for (int i = 0; i < h; i++)
			cin >> v[i];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!table[i][j]) {
					// dfs
					stack<ii> s;
					table[i][j] = 1;
					s.push(ii(i, j));
					while (!s.empty()) {
						ii p = s.top();
						s.pop();
						for (int k = 0; k < 4; k++) {
							int a, b;
							a = p.first + neigh[k][0];
							b = p.second + neigh[k][1];
							if (a >= 0 && a < h && b >= 0 && b < w) {
								if (!table[a][b] && v[a][b] == v[i][j]) {
									table[a][b] = 1;
									s.push(ii(a, b));
								}
							}
						}
					}
					langs[v[i][j] - 'a'].first = v[i][j];
					langs[v[i][j] - 'a'].second++;
				}
			}
		}

		sort(langs.begin(), langs.end(), comp);

		cout << "World #" << counter << endl;
		for (int i = 0; i < 26; i++) {
			if (langs[i].second > 0) {
				cout << (char)langs[i].first << ": " << langs[i].second << endl;
			} else {
				break;
			}
		}

		counter++;
	}

	return 0;
}
