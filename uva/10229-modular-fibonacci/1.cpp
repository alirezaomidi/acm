#include <iostream>
using namespace std;

class QFib {
public:
	QFib() {
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				matrix[i][j] = 1;
		matrix[1][1] = 0;
	}

	long long matrix[2][2];

	QFib(int n) {
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				matrix[i][j] = n;
	}
};

int MOD;

QFib multiply(QFib a, QFib b) {
	QFib res(0);
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				(res.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j]) %= MOD;
	return res;
}

QFib pow2(QFib mat) {
	QFib res(0);
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				(res.matrix[i][j] += mat.matrix[i][k] * mat.matrix[k][j]) %= MOD;
	return res;
}

QFib solve(int n) {
	if (n == 0) return QFib(0);
	else if (n == 1) return QFib();
	else if (n % 2 == 0) {
		return pow2(solve(n / 2));
	} else {
		return multiply(QFib(), solve(n - 1));
	}
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		MOD = (1 << m);
		cout << solve(n).matrix[0][1] << endl;
	}

	return 0;
}