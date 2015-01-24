/*
ID: alireza18
PROG: fracdec
LANG: C++
*/

#include <fstream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

string itos(int n) {
	string res;
	while (n > 0) {
		res += (n % 10) + '0';
		n /= 10;
	}
	reverse(res.begin(), res.end());
	if (res.empty())
		res = '0';
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("fracdec.in");
	ofstream cout("fracdec.out");

	int num, den; cin >> num >> den;
	// long division
	bool ok = true;
	string ans;
	ans += itos(num / den);
	ans += '.';
	num %= den;
	if (num % den == 0) {
		ok = false;
		ans += '0';
	}

	set<ii> nums;
	for (int i = ans.length(); ok; i++) {
		num *= 10;
		int rem = num % den;
		if (rem == 0) {
			ans += itos(num / den);
			break;
		}
		ii p = *nums.lower_bound(make_pair(num, 0));
		if (p.first == num) {
			ans.insert(p.second, 1, '(');
			ans += ')';
			break;
		}
		if (rem == num) {
			ans += '0';
			nums.insert(make_pair(num, i));
			continue;
		}
		ans += itos(num / den);
		nums.insert(make_pair(num, i));
		num = rem;
	}

	for (int i = 0, tmp = 0; i < ans.length(); i++, tmp++) {
		cout << ans[i];
		if (tmp == 75 && i < ans.length() - 1) {
			cout << endl;
			tmp = -1;
		}
		else if (tmp < 75 && i == ans.length() - 1)
			cout << endl;
	}

	return 0;
}