#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	map<char, int> m;
	for (int i = 0; i <= 16; ++i) {
		if (i < 10)
			m[i + '0'] = i;
		else
			m[i + 'A' - 10] = i;
	}
	int original_base, wished_base;
	while (cin >> original_base >> wished_base) {
		string num; cin >> num;
		bool invalid = false;
		int p = 1;
		long long decimal = 0;
		// to decimal
		for (int i = 0; i < num.length(); ++i) {
			if (m[num[i]] >= original_base) {
				invalid = true;
				break;
			}
			decimal = decimal * original_base +  m[num[i]];
		}
		if (invalid)
			cout << num << " is an illegal base " << original_base << " number" << endl;
		// to wished base
		else {
			map<int, char> m2;
			for (int i = 0; i <= 16; ++i) {
				if (i < 10)
					m2[i] = i + '0';
				else
					m2[i] = i + 'A' - 10;
			}
			string wished_num;
			if (decimal == 0)
				wished_num = "0";
			else {
				while (decimal > 0) {
					wished_num += m2[decimal % wished_base];
					decimal /= wished_base;
				}
				reverse(wished_num.begin(), wished_num.end());
			}
			cout << num << " base " << original_base << " = " << wished_num << " base " << wished_base << endl;
		}
	}

	return 0;
}