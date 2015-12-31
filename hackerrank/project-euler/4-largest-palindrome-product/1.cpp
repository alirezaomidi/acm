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
typedef set< int, greater<int> > si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

const int inf = 1e9;

bool ispal(int n) {
	string rev;
	while (n > 0) {
		rev += (char)(n % 10 + '0');
		n /= 10;
	}
	string s = rev;
	reverse(s.begin(), s.end());
	if (s == rev)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);

	si pals;
	for (int i = 100; i < 1000; i++)
		for (int j = 100; j < 1000; j++)
			if (ispal(i * j))
				pals.insert(i * j);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << *pals.upper_bound(n) << endl;
	}

	return 0;
}
