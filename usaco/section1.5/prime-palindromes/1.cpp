/*
 ID: alireza18
 PROG: pprime
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <math.h>
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

bool isPrime(int n) {
	if (n % 2 == 0)
		return false;
	int sqr = sqrt(n);
	for (int i = 3; i <= sqr; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

ifstream fin("pprime.in");
ofstream fout("pprime.out");
int a, b;

void gen(int& len, int currentDigit) {
	static vector<int> digits(len);
	if (currentDigit == (int) ceil((double) len / 2)) {
		// calculate the number
		digits.resize(currentDigit);
		if (len % 2 == 0)
			digits.insert(digits.end(), digits.rbegin(), digits.rend());
		if (len % 2 == 1)
			digits.insert(digits.end(), digits.rbegin() + 1, digits.rend());
		int num = 0;
		for (int digit = 0; digit < len; ++digit)
			num = num * 10 + digits[digit];
		if (num >= a && num <= b && isPrime(num))
			fout << num << endl;
		return;
	}
	for (int d = 0; d <= 9; ++d) {
		if (currentDigit == 0) {
			if (d % 2 == 0)
				continue;
			digits[currentDigit] = d;
			gen(len, currentDigit + 1);
		} else {
			digits[currentDigit] = d;
			gen(len, currentDigit + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	fin >> a >> b;
	for (int i = intlen(a); i <= intlen(b); ++i)
		gen(i, 0);

	return 0;
}
