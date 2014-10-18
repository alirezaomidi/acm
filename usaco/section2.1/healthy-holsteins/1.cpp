/*
 ID: alireza18
 PROG: holstein
 LANG: C++
 */

#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int main () {
	ios::sync_with_stdio(false);
	ifstream cin("holstein.in");
	ofstream cout("holstein.out");
	
	int v; cin >> v;
	vector<int> reqs(v);
	for (int i = 0; i < v; ++i)
		cin >> reqs[i];
	int feed_types; cin >> feed_types;
	vector< vector<int> > feed(feed_types, vector<int>(v));
	for (int i = 0; i < feed_types; ++i)
		for (int j = 0; j < v; ++j)
			cin >> feed[i][j];

	int ways = 1;
	for (int i = 0; i < feed_types; ++i)
		ways *= 2;

	int min_scoops = INT_MAX, choise = 0;
	for (int i = 0; i < ways; ++i) {
		int tmp = i;
		vector<int> current_vits(v, 0);
		int scoops = 0;
		for (int j = 0; tmp > 0; ++j, tmp /= 2) {
			bool still_requires = false;
			if (tmp % 2) {
				++scoops;
				for (int k = 0; k < v; ++k) current_vits[k] += feed[j][k];
			}
		}
		bool ok = true;
		for (int j = 0; j < v; ++j)
			if (current_vits[j] < reqs[j]) {
				ok = false;
				break;
			}
		if (ok) {
			if (min_scoops > scoops) {
				min_scoops = scoops;
				choise = i;
			}
			else if (min_scoops == scoops) {
				// choose set with smallest feedtype numbers
			}
		}
	}
	cout << min_scoops << ' ';
	int i;
	for (i = 1; choise > 1; ++i, choise /= 2) {
		if (choise % 2) cout << i << ' ';
	}
	cout << i << endl;

	return 0;
}