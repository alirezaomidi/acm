#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

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

bool is_more_than_or_equal(const string a, const string b) {
	if (a.length() > b.length())
		return true;
	if (a.length() < b.length())
		return false;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] < b[i])
			return false;
		if (a[i] > b[i])
			return true;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	string biggest = "1000000000000000000000000000000000000000000000000000000000000";
	deque< deque<string> > triangle;
	triangle.push_back(deque<string>(1, "1"));
	cout << 1 << endl;
	bool ok = true;
	for (int i = 1; ok; i++) {
		triangle.push_back(deque<string>());
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				triangle[i].push_back("1");
			} else {
				triangle[i].push_back(add(triangle[i - 1][j - 1], triangle[i - 1][j]));
				if (is_more_than_or_equal(triangle[i][j], biggest))
					ok = false;
			}
			cout << triangle[i][j];
			if (j < i)
				cout << ' ';
			else
				cout << endl;
		}
	}

	return 0;
}