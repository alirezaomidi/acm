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

	int n;
	while (cin >> n) {
		if (!n) break;
		map<si, int> freq;
		int max_freq = 0;
		while (n--) {
			si courses;
			for (int i = 0; i < 5; i++) {
				int c; cin >> c;
				courses.insert(c);
			}
			freq[courses]++;
			max_freq = max(max_freq, freq[courses]);
		}
		int ans = 0;
		for (map<si, int>::iterator i = freq.begin(); i != freq.end(); i++)
			if (i->second == max_freq)
				ans += i->second;
		cout << ans << endl;
	}

	return 0;
}
