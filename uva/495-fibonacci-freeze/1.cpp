#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

deque<string> fibo(5001, "");

string add(const string a, const string b) {
	string res;
	int carry = 0;
	for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--) {
		int tmp = (i >= 0) * (a[i] - '0') + (j >= 0) * (b[j] - '0') + carry;
		carry = tmp / 10;
		tmp %= 10;
		res += tmp + '0';
	}
	if (carry)
		res += carry + '0';
	reverse(res.begin(), res.end());
	return res;
}

string get_fibo(int n) {
	if (fibo[n].length() > 0)
		return fibo[n];
	return fibo[n] = add(get_fibo(n - 2), get_fibo(n - 1));
}

int main() {
	ios::sync_with_stdio(false);
	fibo[0] = "0"; fibo[1] = "1";
	int n;
	while (cin >> n) {
		cout << "The Fibonacci number for " << n << " is " << get_fibo(n) << endl;
	}

	return 0;
}