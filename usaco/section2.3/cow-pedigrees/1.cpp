/*
ID: alireza18
PROG: nocows
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#define MOD 9901

int dp[200][100];
double pow2[200];

int get_bin_trees_count(int n, int k) {
	//cerr << n << ' ' << k << endl;
	if (dp[n][k])
		return dp[n][k];
	if (k == 1)
		return dp[n][k] = (n == 1);
	if (n % 2 == 0)
		return dp[n][k] = 0;
	if (!pow2[k])
		pow2[k] = pow(2, k);
	if (pow2[k] - 1 < n || n < 2 * k - 1)
		return dp[n][k] = 0;
	int res = 0;
	for (int i = 1, j = n - 2; j >= 1; i += 2, j -= 2) {
		(res += get_bin_trees_count(i, k - 1) * get_bin_trees_count(j, k - 1)) %= MOD;
		for (int m = k - 2; m >= 1; m--) {
			(res += get_bin_trees_count(i, m) * get_bin_trees_count(j, k - 1)) %= MOD;
			(res += get_bin_trees_count(j, m) * get_bin_trees_count(i, k - 1)) %= MOD;
		}
	}
	return dp[n][k] = res;
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("nocows.in");
	ofstream cout("nocows.out");

	int n, k; cin >> n >> k;
	cout << get_bin_trees_count(n, k) << endl;

	return 0;
}