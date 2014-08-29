/*
 ID: alireza18
 PROG: sprime
 LANG: C++
 */

#include <fstream>
#include <math.h>
using namespace std;

bool isPrime(int n) {
	if (n == 2)
		return true;
	if (n % 2 == 0 || n < 2)
		return false;
	int sqr = sqrt(n);
	for (int i = 3; i <= sqr; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

ifstream fin("sprime.in");
ofstream fout("sprime.out");
int num = 0;

void dfs(int& len, int currentDigit) {
	for (int d = 1; d <= 9; d++) {
		num = num * 10 + d;
		if (currentDigit < len - 1 && isPrime(num))
			dfs(len, currentDigit + 1);
		else if (currentDigit == len - 1) {
			if (isPrime(num))
				fout << num << endl;
		}
		num /= 10; // backtrack
		if (d > 2)
			d++;
	}
}

int main() {
	int len;
	fin >> len;

	dfs(len, 0);

	return 0;
}
