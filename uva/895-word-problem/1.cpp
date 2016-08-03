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
	vector<string> words;
	while (getline(cin, s) && s != "#")
		words.push_back(s);

	while (getline(cin, s) && s != "#") {
		stringstream ss;
		ss << s;
		string letters;
		map<char, int> puzzle;
		char c;
		while (ss >> c)
			puzzle[c]++;

		int ans = 0;
		for (int i = 0; i < words.size(); i++) {
			int j;
			map<char, int> cur;
			for (j = 0; j < words[i].size(); j++)
				cur[words[i][j]]++;
			bool found = true;
			for (map<char, int>::iterator it = cur.begin(); it != cur.end(); it++)
				if (it->second > puzzle[it->first]) {
					found = false;
					break;
				}
			if (found)
				ans++;
		}

		cout << ans << endl;
	}

	return 0;
}
