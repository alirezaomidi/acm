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

bool check(string vars, map<char, string>& cons) {
	for (int i = 0; i < vars.size(); i++)
		for (int j = i + 1; j < vars.size(); j++)
			if (cons[vars[j]].find(vars[i]) != string::npos)
				return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	cin.get();
	bool first = true;
	while (t--) {
		cin.get();
		string s;
		getline(cin, s);
		// cerr << s << endl;
		stringstream ss;
		ss << s;
		string vars;
		while (ss >> s)
			vars += s;

		getline(cin, s);
		// cerr << s << endl;
		ss.clear();
		ss << s;
		map<char, string> cons;
		while (ss >> s) {
			if (s[1] == '>')
				cons[s[2]] += s[0];
			else
				cons[s[0]] += s[2];
		}

		if (!first)
			cout << endl;
		first = false;

		bool hasans = false;
		sort(vars.begin(), vars.end());
		do {
			if (check(vars, cons)) {
				hasans = true;
				cout << vars[0];
				for (int i = 1; i < vars.size(); i++)
					cout << ' ' << vars[i];
				cout << endl;
			}
		} while (next_permutation(vars.begin(), vars.end()));
		if (!hasans)
			cout << "NO" << endl;
	}

	return 0;
}
