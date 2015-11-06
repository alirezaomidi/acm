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
		vvii v(26, vii());
		for (int i = 0; i < n; i++) {
			ii in; char c;
			cin >> c >> in.first >> in.second;
			v[c - 'A'].push_back(in);
		}

		vi tog(26, 0);
		for (int i = 0; i <= 1000; i++) {
			int total = -1;
			for (int j = 0; j < 26; j++) {
				for (int k = 0; k < v[j].size(); k++) {
					ii in = v[j][k];
					if (i == in.first || i == in.second) {
						tog[j] = ~tog[j];
					}
				}
				if (tog[j])
					total++;
			}
			if (total > -1)
				cout << (char)(total + 'A');
		}
		cout << endl;

	}

	return 0;
}
