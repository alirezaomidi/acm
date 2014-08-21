/*
 ID: alireza18
 PROG: milk
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first)
		return true;
	if (a.first > b.first)
		return false;
	if (a.second >= b.second)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int n, m;
	fin >> n >> m;
	deque<pair<int, int> > v;
	while (m) {
		int a, b;
		fin >> a >> b;
		v.push_back(make_pair(a, b));
		--m;
	}
	sort(v.begin(), v.end());

	int sum = 0, minPrice = 0;
	for (deque<pair<int, int> >::iterator itr = v.begin(); sum != n && itr != v.end();
			++itr) {
		if (itr->second <= n - sum) {
			minPrice += itr->first * itr->second;
			sum += itr->second;
		} else {
			minPrice += itr->first * (n - sum);
			sum = n;
		}
	}
	fout << minPrice << endl;

	return 0;
}
