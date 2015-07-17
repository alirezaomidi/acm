/*
ID: alireza18
PROG: kimbits
LANG: C++
*/

#include <fstream>
#include <vector>
using namespace std;

typedef unsigned int ui;
typedef vector<ui> vi;
typedef vector<vi> vvi;

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("kimbits.in");
	ofstream cout("kimbits.out");

	ui n, len, order;
	cin >> n >> len >> order;

	vvi dp(n + 1, vi(len + 1, 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= len; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

	while (n--) {
		ui c = dp[n][len];
		if (order > c) {
			cout << '1';
			order -= c;
			len--;
		} else {
			cout << '0';
		}
	}
	cout << endl;

	return 0;
}