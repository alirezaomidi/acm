/*
 ID: alireza18
 PROG: lamps
 LANG: C++
 */

#include <fstream>
#include <set>
#include <vector>
using namespace std;

#define MAX_POSSIBLE 8

vector<int> key(vector<int>& v, int key_num) {
	int step, init;
	if (key_num == 1) {
		init = 0;
		step = 1;
	} else if (key_num == 2) {
		init = 0;
		step = 2;
	} else if (key_num == 3) {
		init = 1;
		step = 2;
	} else if (key_num == 4) {
		init = 0;
		step = 3;
	}
	vector<int> tmp(v);
	for (int i = init; i < v.size(); i += step)
		tmp[i] = !v[i];
	return tmp;
}

set< pair<vector<int>, int> > all_possible;
void gen_all(vector<int> v) {
	static int level = 1, count = 0;
	if (level == 5) {
		all_possible.insert(make_pair(v, count));
		return;
	}
	for (int i = 0; i < 2; i++) {
		level++;
		if (i == 1) {
			count++;
			gen_all(key(v, level - 1));
			count--;
		} else {
			gen_all(v);
		}
		level--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("lamps.in");
	ofstream cout("lamps.out");
	
	int n, c; cin >> n >> c;

	vector<int> current(n, 1);
	vector<int> final(n, -1);

	int index; cin >> index;
	while (index != -1) {
		final[index - 1] = 1;
		cin >> index;
	}
	cin >> index;
	while (index != -1) {
		final[index - 1] = 0;
		cin >> index;
	}

	gen_all(current);

	bool impossible = true;
	for (set< pair< vector<int>, int> >::iterator i = all_possible.begin(); i != all_possible.end(); ++i)
		if (i->second <= c && (i->second - c) % 2 == 0) {
			bool ok = true;
			for (int j = 0; j < n; j++)
				if (final[j] != -1 && i->first[j] != final[j]) {
					ok = false;
					break;
				}
			if (ok) {
				for (int j = 0; j < n; j++)
					cout << i->first[j];
				cout << endl;
				impossible = false;
			}
		}

	if (impossible) cout << "IMPOSSIBLE" << endl;
	
	return 0;
}