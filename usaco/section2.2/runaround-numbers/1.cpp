/*
 ID: alireza18
 PROG: runround
 LANG: C++
 */

#include <fstream>
#include <climits>
#include <set>
#include <vector>
using namespace std;

bool is_runaround(vector<int> n) {
	int current_index = 0, digits_touched = 0;
	do {
		(current_index += n[current_index]) %= n.size();
		digits_touched++;
	} while (current_index > 0 && digits_touched < n.size());
	if (current_index == 0 && digits_touched == n.size()) return true;
	return false;
}

unsigned long to_ulong(vector<int>& n) {
	unsigned long res = 0;
	for (int i = 0; i < n.size(); i++)
		res = res * 10 + n[i];
	return res;
}

set<unsigned long> s;
void gen_runaround_nums(vector<int> tmp) {
	static bool used[9] = {false};
	for (int i = 1; i <= 9; i++) {
		if (!used[i - 1]) {
			tmp.push_back(i);
			if (is_runaround(tmp))
				s.insert(to_ulong(tmp));
			used[i - 1] = true;
			gen_runaround_nums(tmp);
			used[i - 1] = false;
			tmp.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("runround.in");
	ofstream cout("runround.out");
	
	int number; cin >> number;
	gen_runaround_nums(vector<int>());
	for (set<unsigned long>::iterator i = s.begin(); i != s.end(); ++i)
		if (*i > number) {
			cout << *i << endl;
			break;
		}

	return 0;
}