/*
 ID: alireza18
 PROG: combo
 LANG: C++
 */

#include <fstream>
#include <vector>
#include <set>
using namespace std;

void gen(set<vector<int> >& combs, vector<int>& s, int& n, int level) {
	static vector<int> comb(s);
	if (level == 3) {
		if (combs.find(comb) != combs.end()) return;
		combs.insert(comb);	return;
	}
	for (int i = -2; i <= 2; ++i) {
		comb[level] = (s[level] + i) % n + ((s[level] + i) % n <= 0) * n;
		gen(combs, s, n, level + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	ifstream fin("combo.in");
	ofstream fout("combo.out");
	int n;
	fin >> n;
	vector<int> fj(3);
	for (int i = 0; i < 3; ++i) fin >> fj[i];
	vector<int> master(3);
	for (int i = 0; i < 3; ++i) fin >> master[i];
	set<vector<int> > combs;
	if (n <= 5)	fout << n * n * n << endl;
	else {
		gen(combs, fj, n, 0);
		gen(combs, master, n, 0);
		fout << combs.size() << endl;
	}

	return 0;
}
