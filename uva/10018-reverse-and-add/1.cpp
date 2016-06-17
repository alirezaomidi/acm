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

string int2str(ll n) {
	stringstream ss;
	ss << n;
	string s;
	ss >> s;
	return s;
}

ll str2int(string s) {
	stringstream ss;
	ss << s;
	ll n;
	ss >> n;
	return n;
}

ll rev_and_add(ll n) {
	string s = int2str(n);
	reverse(s.begin(), s.end());
	return n + str2int(s);
}

bool ispal(ll n) {
	string s = int2str(n);
	for (int i = 0; i < s.size() / 2; i++)
		if (s[i] != s[s.size() - i - 1])
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);

	int n; cin >> n;
	while (n--) {
		ll p; cin >> p;
		int iters = 0;
		while (!ispal(p)) {
			p = rev_and_add(p);
			iters++;
		}
		cout << iters << ' ' << p << endl;
	}

	return 0;
}
