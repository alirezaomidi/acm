#include <bits/stdc++.h>

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

	int n, k;
	while (cin >> n >> k && n && k) {
		vi student(n, 0);
		int cur = 1, out = 0;
		vi done(n, 0);
		int dones = 0;

		for (int i = 0; dones < n; ++i %= n) {
			while (done[i])
				++i %= n;

			if (out == 0) {
				out = cur;
				cur++;
				if (cur > k)
					cur = 1;
			}

			if (student[i] + out > 40) {
				out -= 40 - student[i];
				// cerr << i + 1 << ' ' << 40 - student[i] << ' ' << 40 << endl;
				student[i] = 40;
			} else {
				student[i] += out;
				// cerr << i + 1 << ' ' << out << ' ' << student[i] << endl;
				out = 0;
			}

			if (student[i] == 40) {
				done[i] = 1;
				dones++;
				cout << setw(3) << right << i + 1;
			}
		}
		cout << endl;
	}

	return 0;
}
