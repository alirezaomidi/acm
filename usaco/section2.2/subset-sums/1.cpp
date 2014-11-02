/*
 ID: alireza18
 PROG: subset
 LANG: C++
 */

#include <fstream>
using namespace std;

unsigned p[391][40];
int n;

unsigned partitions() {
	int sum = n * (n + 1) / 2;
	if (sum % 2)
		return 0;

	sum /= 2;
	for (int i = 0; i <= n; i++)
		p[0][i] = 1;

	for (int i = 1; i <= sum; i++) {
		for (int j = 1; j <= n; j++) {
			if (j <= i)
				p[i][j] = p[i][j - 1] + p[i - j][j - 1];
			else
				p[i][j] = p[i][j - 1];
		}
	}
	return p[sum][n];
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("subset.in");
	ofstream cout("subset.out");

	cin >> n;
	cout << partitions() / 2 << endl;

	return 0;
}