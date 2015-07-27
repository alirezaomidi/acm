#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;

const int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	cin.ignore(); cin.ignore();
	bool first = true;
	while (t--) {
		map<string, int> freq;
		int population = 0;
		string s;
		while (getline(cin, s)) {
			if (s.empty())
				break;
			freq[s]++;
			population++;
		}
		if (!first)
			cout << endl;
		else
			first = false;
		for (map<string, int>::iterator it = freq.begin(); it != freq.end(); it++) {
			cout << it->first << ' ' << setprecision(4) << fixed << (double)it->second / population * 100 << endl;
		}
	}

	return 0;
}