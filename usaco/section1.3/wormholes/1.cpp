/*
 ID: alireza18
 PROG: wormhole
 LANG: C++
 */

#include <fstream>
using namespace std;

#define MAX_N 12

pair<int, int> holes[MAX_N + 1];
int next_on_right[MAX_N + 1];
int match[MAX_N + 1];
int n;

bool loop_exists() {
	for (int start = 1; start <= n; ++start) {
		int pos = start;
		for (int count = 0; count < n; ++count)
		pos = next_on_right[match[pos]];
		if (pos != 0) return true;
	}
	return false;
}

int count_loops() {
	int i, total = 0;
	for (i = 1; i <= n; ++i)
		if (match[i] == 0)
			break;
	if (i > n) {
		if (loop_exists()) return 1;
		return 0;
	}

	for (int j = i + 1; j <= n; ++j)
		if (match[j] == 0) {
			match[i] = j;
			match[j] = i;
			total += count_loops();
			match[i] = match[j] = 0;
		}
	return total;
}

int main() {
	ios::sync_with_stdio(false);
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");
	fin >> n;
	for (int i = 1; i <= n; ++i)
		fin >> holes[i].first >> holes[i].second;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (holes[i].second == holes[j].second && holes[i].first < holes[j].first)
				if (next_on_right[i] == 0 || holes[j].first < holes[next_on_right[i]].first)
					next_on_right[i] = j;
	fout << count_loops() << endl;
	return 0;
}
