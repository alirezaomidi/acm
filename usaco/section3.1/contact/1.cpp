/*
ID: alireza18
PROG: contact
LANG: C++
*/

#include <fstream>
#include <string>
#include <map>
#include <set>
using namespace std;

typedef pair<int, string> pis;

struct Comp {
	bool operator()(pis a, pis b) {
		if (a.first < b.first)
			return true;
		if (a.first > b.first)
			return false;
		if (a.second.length() < b.second.length())
			return false;
		if (a.second.length() > b.second.length())
			return true;
		if (a.second < b.second)
			return false;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("contact.in");
	ofstream cout("contact.out");

	int a, b, n; cin >> a >> b >> n;
	string s, tmp;
	while (cin >> tmp)
		s += tmp;

	map<string, int> freqs;

	for (int i = 0; i < s.length(); i++) {
		if (i + a <= s.length()) {
			string tmp = s.substr(i, a);
			freqs[tmp]++;
			for (int j = a; j < b && i + j < s.length(); j++) {
				tmp += s[i + j];
				freqs[tmp]++;
			}
		}
	}

	set<pair<int, string>, Comp> ans;
	for (map<string, int>::iterator i = freqs.begin(); i != freqs.end(); i++)
		ans.insert(make_pair(i->second, i->first));

	int freq = -1;
	int count = 0, inline_count = 0;
	for (set<pair<int, string>, Comp>::reverse_iterator i = ans.rbegin(); i != ans.rend(); i++) {
		if (freq != i->first) {
			count++;
			if (count > n)
				break;
			if (freq == -1 || inline_count == 0)
				cout << i->first << endl;
			else
				cout << endl << i->first << endl;
			freq = i->first;
			cout << i->second;
			inline_count = 1;
		} else {
			inline_count++;
			if (inline_count == 1)
				cout << i->second;
			else
				cout << ' ' << i->second;
		}
		if (inline_count == 6) {
			cout << endl;
			inline_count = 0;
		}
	}
	if (inline_count > 0)
		cout << endl;

	return 0;
}