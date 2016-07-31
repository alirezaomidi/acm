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

	string s;
	while (cin >> s) {
		if (s[0] == '-') break;
		if (s.substr(0, 2) == "0x") {
			stringstream ss;
			ss << s;
			int ans;
			ss >> hex >> ans;
			cout << dec << ans << endl;
		} else {
			stringstream ss;
			ss << s;
			int ans;
			ss >> ans;
			cout << "0x" << hex << uppercase << ans << endl;
		}
	}

	return 0;
}
