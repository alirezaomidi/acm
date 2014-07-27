/*
ID: alireza18
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> firstInterval, pair<int, int> secondInterval) {
	if (firstInterval.first < secondInterval.first) {
		return true;
	} else if (firstInterval.first == secondInterval.first) {
		if (firstInterval.second >= secondInterval.second) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

int main() {
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");

	int n;
	fin >> n;

	vector< pair<int, int> > intervals(n);

	for (int currentInterval = 0; currentInterval < n; currentInterval++) {
		fin >> intervals[currentInterval].first >> intervals[currentInterval].second;
	}

	sort(intervals.begin(), intervals.end(), compare);

	int atLeastOneCow = intervals[0].second - intervals[0].first, noCow = 0;
	int longestAtLeastOneCow = atLeastOneCow, longestNoCow = 0;
	int max = intervals[0].second;

	for (int currentInterval = 1; currentInterval < n; currentInterval++) {
		if (intervals[currentInterval].second > max) {
			if (intervals[currentInterval].first <= max) {
				atLeastOneCow += intervals[currentInterval].second - max;
				if (atLeastOneCow > longestAtLeastOneCow) {
					longestAtLeastOneCow = atLeastOneCow;
				}
			} else {
				noCow = intervals[currentInterval].first - max;
				if (noCow > longestNoCow) {
					longestNoCow = noCow;
				}
				atLeastOneCow = intervals[currentInterval].second - intervals[currentInterval].first;
			}
			max = intervals[currentInterval].second;
		}
	}

	fout << longestAtLeastOneCow << " " << longestNoCow << endl;

	return 0;
}
