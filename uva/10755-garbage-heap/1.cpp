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

const ll inf = 3e9;

int main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	bool first = true;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		vector<vvi> v(a, vvi(b, vi(c, 0)));

		for (int k = 0; k < a; k++)
			for (int i = 0; i < b; i++)
				for (int j = 0; j < c; j++) {
					cin >> v[k][i][j];
					if (i > 0) v[k][i][j] += v[k][i - 1][j];
					if (j > 0) v[k][i][j] += v[k][i][j - 1];
					if (i > 0 && j > 0) v[k][i][j] -= v[k][i - 1][j - 1];
				}

		ll maxx = -inf;
		for (int i = 0; i < b; i++)
			for (int j = 0; j < c; j++)
				for (int k = i; k < b; k++)
					for (int l = j; l < c; l++) {
						ll sum = 0, ans = -inf;
						for (int m = 0; m < a; m++) {
							sum += v[m][k][l];
							if (i > 0) sum -= v[m][i - 1][l];
							if (j > 0) sum -= v[m][k][j - 1];
							if (i > 0 && j > 0) sum += v[m][i - 1][j - 1];
							ans = max(ans, sum);
							if (sum < 0) sum = 0;
						}
						maxx = max(maxx, ans);
					}
		if (!first)
			cout << endl;
		else
			first = false;
		cout << maxx << endl;
	}

	return 0;
}
