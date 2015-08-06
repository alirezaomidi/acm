#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iomanip>
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

long dp[105][105];

int main() {
	ios::sync_with_stdio(false);

	for (int i = 0; i <= 100; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0)
			break;
		cout << n << " things taken " << m << " at a time is " << dp[n][m] << " exactly." << endl;
	}

	return 0;
}
