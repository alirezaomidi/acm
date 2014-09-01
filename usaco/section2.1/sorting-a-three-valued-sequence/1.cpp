/*
 ID: alireza18
 PROG: sort3
 LANG: C++
 */

#include <fstream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");

	int n;
	fin >> n;
	vector<int> a(n);
	vector<int> counts(3, 0);
	for (int i = 0; i < n; ++i) {
		fin >> a[i];
		++counts[a[i] - 1];
	}

	int count = 0;
	for (int i = 0; i < counts[0]; ++i) {
		if (a[i] == 2)
			for (int j = counts[0]; j < n; ++j)
				if (a[j] == 1) {
					swap(a[i], a[j]);
					++count;
					break;
				}
		if (a[i] == 3)
			for (int j = n - 1; j >= 0; --j)
				if (a[j] == 1) {
					swap(a[i], a[j]);
					++count;
					break;
				}
	}
	for (int i = counts[0]; i < counts[0] + counts[1]; ++i)
		if (a[i] == 3)
			++count;

	fout << count << endl;

	return 0;
}
