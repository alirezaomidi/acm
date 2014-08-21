/*
 ID: alireza18
 PROG: barn1
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	int m, s, c;
	fin >> m >> s >> c;
	deque<int> stalls(c), intervals;

	for (int i = 0; i < c; ++i)
		fin >> stalls[i];
	sort(stalls.begin(), stalls.end());

	for (int i = 1; i < c; ++i)
		intervals.push_back(stalls[i] - stalls[i - 1] - 1);
	sort(intervals.begin(), intervals.end());

	int ans = stalls.back() - stalls.front() + 1;
	if (m > c)
		ans = c;
	else {
		while (m > 1) {
			ans -= intervals.back();
			intervals.pop_back();
			m--;
		}
	}
	fout << ans << endl;

	return 0;
}
