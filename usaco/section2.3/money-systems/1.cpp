/*
ID: alireza18
PROG: money
LANG: C++
*/

#include <fstream>
#include <algorithm>
using namespace std;

#define MAX_N 10000
#define MAX_V 25

long long ways[MAX_N + 1][MAX_V];
int coins[MAX_V];
int coin_count, money;

long long get_ways(int n, int start_index) {
	if (n < 0)
		return 0;
	if (ways[n][start_index])
		return ways[n][start_index];
	if (n < coins[0])
		return 0;
	long long total = 0;
	for (int i = start_index; i >= 0; i--) {
		total += get_ways(n - coins[i], i);
	}
	ways[n][start_index] = total;
	return total;
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("money.in");
	ofstream cout("money.out");
	cin >> coin_count >> money;
	for (int i = 0; i < coin_count; i++)
		cin >> coins[i];
	sort(coins, coins + coin_count);
	for (int i = 0; i < coin_count; i++) {
		ways[coins[0]][i] = 1;
		ways[0][i] = 1;
	}
	cout << get_ways(money, coin_count - 1) << endl;

	return 0;
}