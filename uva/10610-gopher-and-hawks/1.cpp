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
#include <sstream>
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

double dist(dd a, dd b, int v) {
	return sqrt(pow(b.second - a.second, 2.) + pow(b.first - a.first, 2.)) / v;
}

int main() {
	ios::sync_with_stdio(false);

	int velo, m;
	while (cin >> velo >> m) {
		if (!velo && !m) break;
		string tmp;
		vector< dd > v;
		dd s, t;
		cin >> s.first >> s.second;
		v.push_back(s);
		cin >> t.first >> t.second;
		v.push_back(t);
		cin.ignore();
		while (getline(cin, tmp)) {
			if (tmp.empty()) break;
			stringstream ss;
			ss << tmp;
			dd a;
			ss >> a.first >> a.second;
			v.push_back(a);
		}

		// bfs
		queue<int> q;
		q.push(0);
		vi layer(v.size(), -1);
		layer[0] = 0;
		while (!q.empty()) {
			int point = q.front();
			if (point == 1) break;
			q.pop();
			for (int i = 1; i < v.size(); i++) {
				// cerr << v[i].first << ", " << v[i].second << endl;
				// cerr << point << " -> " << i << " = " << dist(v[point], v[i], velo) << endl;
				if (dist(v[point], v[i], velo) <= m * 60 && layer[i] == -1) {
					q.push(i);
					layer[i] = layer[point] + 1;
				}
			}
		}
		if (layer[1] > -1) {
			cout << "Yes, visiting " << layer[1] - 1 << " other holes." << endl;
		} else {
			cout << "No." << endl;
		}
	}

	return 0;
}
