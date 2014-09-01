/*
 ID: alireza18
 PROG: frac1
 LANG: C++
 */

#include <fstream>
#include <set>
using namespace std;

struct Compare {
	bool operator()(pair<int, int> i, pair<int, int> j) {
		return i.first * j.second < j.first * i.second;
	}
};

int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

void simplify(int& i, int& j) {
	int g;
	while ((g = gcd(i, j)) != 1) {
		i /= g;
		j /= g;
	}
}

int main() {
	ios::sync_with_stdio(false);
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");

	int n;
	fin >> n;

	set<pair<int, int>, Compare> fracs;

	for (int j = 1; j <= n; ++j) {
		for (int i = 0; i <= j; ++i) {
			int numerator = i, denominator = j;
			simplify(numerator, denominator);
			fracs.insert(make_pair(numerator, denominator));
		}
	}

	for (set<pair<int, int> >::iterator i = fracs.begin(); i != fracs.end();
			++i)
		fout << i->first << '/' << i->second << endl;

	return 0;
}
