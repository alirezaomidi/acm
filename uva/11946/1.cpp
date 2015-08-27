#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
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

const int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);

	map<char, char> mp;

	mp['0'] = 'O'; mp['1'] = 'I'; mp['2'] = 'Z';
	mp['3'] = 'E'; mp['4'] = 'A'; mp['5'] = 'S';
	mp['6'] = 'G'; mp['7'] = 'T'; mp['8'] = 'B';
	mp['9'] = 'P';

	int t; cin >> t;
	bool first = true;
	cin.ignore();
	while (t--) {
		if (!first)
			cout << endl;
		else
			first = false;
		string s;
		while (getline(cin, s)) {
			if (s.empty()) break;
			for (int i = 0; i < s.length(); i++) {
				if (s[i] >= '0' && s[i] <= '9')
					s[i] = mp[s[i]];
			}
			cout << s << endl;
		}
	}

	return 0;
}
