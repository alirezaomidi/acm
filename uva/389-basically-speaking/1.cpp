#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm>
using namespace std;

map<int, char> num_to_char;
map<char, int> char_to_num;

int to_decimal(string s, int base) {
	int decimal = 0;
	for (int i = s.length() - 1, p = 1; i >= 0; i--, p *= base) {
		decimal += char_to_num[s[i]] * p;
	}
	return decimal;
}

string from_decimal(int decimal, int base) {
	string res;
	if (decimal == 0)
		res = "0";
	while (decimal > 0) {
		res += num_to_char[decimal % base];
		decimal /= base;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	for (int i = 0; i < 16; i++) {
		char c = (i < 10 ? '0' : 'A' - 10);
		num_to_char[i] = i + c;
		char_to_num[i + c] = i;
	}

	string num;
	int from_base, to_base;
	while (cin >> num >> from_base >> to_base) {
		string res = from_decimal(to_decimal(num, from_base), to_base);
		cout << setw(7);
		if (res.length() > 7)
			cout << "ERROR";
		else
			cout << res;
		cout << endl;
	}

	return 0;
}