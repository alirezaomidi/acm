/*
 ID: alireza18
 PROG: zerosum
 LANG: C++
 */


#include <fstream>
using namespace std;

int n;
char op[9];

ifstream cin("zerosum.in");
ofstream cout("zerosum.out");

bool is_zero() {
	int sum = 0, current = 0;
	char todo = '+';
	for (int i = 1; i <= n; i++) {
		current = current * 10 + i;
		if (i == n) {
			if (todo == '+')
				sum += current;
			else
				sum -= current;
			break;
		}
		else if (op[i - 1] == '+') {
			if (todo == '+')
				sum += current;
			else
				sum -= current;
			current = 0;
			todo = '+';
		}
		else if (op[i - 1] == '-') {
			if (todo == '+')
				sum += current;
			else
				sum -= current;
			current = 0;
			todo = '-';
		}
	}
	if (sum)
		return false;
	return true;
}

void gen() {
	static int current = 0;
	if (current == n - 1) {
		if (is_zero()) {
			for (int i = 1; i <= n; i++) {
				cout << i;
				if (i < n)
					cout << op[i - 1];
			}
			cout << endl;
		}
		return;
	}
	op[current] = ' ';
	current++;
	gen();
	op[current - 1] = '+';
	gen();
	op[current - 1] = '-';
	gen();
	current--;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		op[i] = ' ';
	gen();

	return 0;
}