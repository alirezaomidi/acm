/*
ID: alireza18
PROG: stamps
LANG: C++
*/

#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> vi;

const short inf = 250;

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("stamps.in");
	ofstream cout("stamps.out");

	int k, n; cin >> k >> n;
	vi stamps(n, 0);
	for (int i = 0; i < n; i++)
		cin >> stamps[i];

	vi dp; dp.push_back(0);
	for (int i = 1; ; i++) {
		int count = inf;
		for (int j = 0; j < n; j++)
			if (stamps[j] <= i)
				count = min(count, dp[i - stamps[j]] + 1);
		if (count > k)
			break;
		dp.push_back(count);
	}
	cout << dp.size() - 1 << endl;

	return 0;
}