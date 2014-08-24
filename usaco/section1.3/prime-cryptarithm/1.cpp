/*
 ID: alireza18
 PROG: crypt1
 LANG: C++
 */

#include <fstream>
#include <vector>
using namespace std;

int intlen(int n) {
	int len = 0;
	while (n > 0) {
		len++;
		n /= 10;
	}
	return len;
}

bool check(vector<int>& set, const int& n, int number, int limit) {
	if (intlen(number) > limit)
		return false;

	bool found = false;
	while (number > 0) {
		int digit = number % 10;
		for (int i = 0; i < n; ++i)
			if (digit == set[i])
				found = true;
		if (found)
			found = false;
		else
			return false;
		number /= 10;
	}
	return true;
}

void dfs(vector<int>& set, const int& n, vector<int>& abcde, int level, int& solutions) {
	if (level == 5) {
		int abc = abcde[0] * 100 + abcde[1] * 10 + abcde[2];
		int p1 = abc * abcde[3];
		int p2 = abc * abcde[4];
		if (check(set, n, p1, 3) && check(set, n, p2, 3) && check(set, n, p1 + p2 * 10, 4))
			solutions++;
		return;
	}
	for (int i = 0; i < n; ++i) {
		abcde[level] = set[i];
		dfs(set, n, abcde, level + 1, solutions);
	}
}

int main() {
	ios::sync_with_stdio(false);
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");

	int n;
	fin >> n;
	vector<int> set(n);
	for (int i = 0; i < n; ++i)
		fin >> set[i];

	int solutions = 0;
	vector<int> abcde(5);
	dfs(set, n, abcde, 0, solutions);

	fout << solutions << endl;

	return 0;
}
