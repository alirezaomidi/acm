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
	bool first = true;
	while (t--) {
		int n, sg, sb; cin >> n >> sg >> sb;
		multiset< int, greater<int> > g, b;
		for (int i = 0; i < sg; i++) {
			int tmp; cin >> tmp;
			g.insert(tmp);
		}
		for (int i = 0; i < sb; i++) {
			int tmp; cin >> tmp;
			b.insert(tmp);
		}

		ll counter = 0;
		vi gtmp, btmp;
		while (!g.empty() && !b.empty()) {
			multiset< int, greater<int> >::iterator git = g.begin(), bit = b.begin();
			for (int i = 0; i < n && git != g.end() && bit != b.end(); i++) {
				if (*git > *bit)
					gtmp.push_back(*git - *bit);
				else if (*git < *bit)
					btmp.push_back(*bit - *git);
				g.erase(git); b.erase(bit);
				git++; bit++;
			}
			for (int i = 0; i < gtmp.size(); i++)
				g.insert(gtmp[i]);
			for (int i = 0; i < btmp.size(); i++)
				b.insert(btmp[i]);
			gtmp.clear(); btmp.clear();
		}

		first ? first = false : cout << endl;

		if (g.size() == 0 && b.size() == 0)
			cout << "green and blue died" << endl;
		else if (g.size() > 0) {
			cout << "green wins" << endl;
			for (multiset< int, greater<int> >::iterator it = g.begin(); it != g.end(); it++)
				cout << *it << endl;
		} else {
			cout << "blue wins" << endl;
			for (multiset< int, greater<int> >::iterator it = b.begin(); it != b.end(); it++)
				cout << *it << endl;
		}
	}

	return 0;
}
