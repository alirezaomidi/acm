/*
ID: alireza18
PROG: humble
LANG: C++
*/

#include <fstream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> vi;

const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("humble.in");
	ofstream cout("humble.out");

	int k, n; cin >> k >> n;

	vi prime(k, 0);
	vi humble; humble.push_back(1);
	vi index(k, 0);

	for (int i = 0; i < k; i++)
		cin >> prime[i];

	while (humble.size() <= n) {
		int minn = inf;
		for (int i = 0; i < k; i++)
			for (int j = index[i]; j < humble.size(); j++) {
				int next = prime[i] * humble[j];
				if (next <= humble.back())
					continue;
				if (next < minn)
					minn = next;
				index[i] = j;
				break;
			}
		humble.push_back(minn);
	}

	cout << humble.back() << endl;

	return 0;
}