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

	int n;
	while (cin >> n && n) {
		int ans = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			int tmp; cin >> tmp;
			sum += tmp;
			ans = max(ans, sum);
			if (sum < 0) sum = 0;
		}
		if (ans > 0)
			cout << "The maximum winning streak is " << ans << '.' << endl;
		else
			cout << "Losing streak." << endl;
	}

	return 0;
}
