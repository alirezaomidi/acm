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
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;

const int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);

	int n, m;
	while (cin >> n >> m) {
		if (!n && !m)
			break;

		vi heads(n, 0), knights(m, 0);
		for (int i = 0; i < n; i++)
			cin >> heads[i];
		for (int i = 0; i < m; i++)
			cin >> knights[i];

		sort(heads.begin(), heads.end());
		sort(knights.begin(), knights.end());

		int expense = 0;
		bool ok = true;
		for (int i = 0, j = 0; i < n;) {
			if (j >= m) {
				ok = false;
				break;
			}
			if (heads[i] <= knights[j]) {
				expense += knights[j];
				i++; j++;
			} else
				j++;
		}
		if (!ok)
			cout << "Loowater is doomed!" << endl;
		else
			cout << expense << endl;
	}

	return 0;
}
