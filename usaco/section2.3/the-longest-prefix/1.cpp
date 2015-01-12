/*
ID: alireza18
PROG: prefix
LANG: C++
*/

#include <fstream>
#include <string>
using namespace std;

string prims[200];
bool till_here[200002] = { true };

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("prefix.in");
	ofstream cout("prefix.out");
	int n; string tmp;
	for (n = 0; cin >> tmp; n++) {
		if (tmp != ".")
			prims[n] = tmp;
		else
			break;
	}
	string s;
	while (cin >> tmp)
		s += tmp;

	int ans = 0;
	for (int i = 0; i <= s.length(); i++) {
		if (till_here[i]) {
			ans = i;
			if (i == s.length())
				break;
			for (int j = 0; j < n; j++)
				if (i + prims[j].length() <= s.length() && s.substr(i, prims[j].length()) == prims[j])
					for (int k = i; k <= i + prims[j].length(); k++)
						till_here[k] = true;
		}
	}
	cout << ans << endl;

	return 0;
}