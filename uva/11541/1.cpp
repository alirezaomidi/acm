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

int main() {
	ios::sync_with_stdio(false);

	int tst; cin >> tst;
	for (int t = 1; t <= tst; t++) {
		string s; cin >> s;
		string ans;
		char c; int len = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'A') {
				if (i > 0) {
					for (int j = 0; j < len; j++)
						ans += c;
				}
				c = s[i];
				len = 0;
			} else {
				len = len * 10 + (s[i] - '0');
			}
		}
		for (int j = 0; j < len; j++)
			ans += c;
		cout << "Case " << t << ": " << ans << endl;
	}

	return 0;
}
