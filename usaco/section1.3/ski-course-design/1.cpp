/*
 ID: alireza18
 PROG: skidesign
 LANG: C++
 */

#include <fstream>
#include <vector>
#include <climits>
using namespace std;

inline int pow2(int n) {
	return n * n;
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("skidesign.in");
	ofstream cout("skidesign.out");

	int n; cin >> n;
	vector<int> hill(n);
	int max_h = 0;
	for (int i = 0; i < n; ++i) {
		cin >> hill[i];
		if (max_h < hill[i])
			max_h = hill[i];
	}
	cin.close();

	int min = INT_MAX;
	for (int i = 0; i <= max_h - 17; ++i) {
		int money = 0;
		for (int current_hill = 0; current_hill < n; ++current_hill) {
			if (hill[current_hill] < i)
				money += pow2(i - hill[current_hill]);
			else if (hill[current_hill] > i + 17)
				money += pow2(hill[current_hill] - i - 17);
		}
		if (min > money)
			min = money;
	}
	cout << min << endl;
	cout.close();

	return 0;
}