/*
 ID: alireza18
 PROG: ariprog
 LANG: C++
 */

#include <fstream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");

	int n, m;
	fin >> n >> m;

	bool bisquare[251 * 251 * 2] = { false };
	for (int i = 0; i <= m; ++i)
		for (int j = i; j <= m; ++j)
			bisquare[i * i + j * j] = true;

	int up = m * m * 2;
	vector<pair<int, int> > res;
	for (int d = 1; d <= up; ++d) {
		for (int a = 0; a < up; ++a) {
			if (a + d * (n - 1) > up)
				break;
			bool ok = true;
			for (int i = 0; i < n; ++i)
				if (!bisquare[a + i * d]) {
					ok = false;
					break;
				}
			if (ok)
				res.push_back(make_pair(a, d));
		}
	}
	if (res.empty())
		fout << "NONE" << endl;
	else
		for (int i = 0; i < (int)res.size(); ++i)
			fout << res[i].first << ' ' << res[i].second << endl;

	return 0;
}
