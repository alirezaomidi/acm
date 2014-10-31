/*
 ID: alireza18
 PROG: preface
 LANG: C++
 */

#include <fstream>
#include <map>
#include <string>
using namespace std;

int numbers[3500][7]; // for all numbers from 1 to 3499: count of Is, Vs, Xs, etc.

int sp_nums[6] = {4, 9, 40, 90, 400, 900};
int specials[6][7] = {{1, 1}, {1, 0, 1}, {0, 0, 1, 1}, {0, 0, 1, 0, 1}, {0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 1, 0, 1}}; // 4, 9, 40, 90, 400, 900

int ans[7];
char chars[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int chars_num[7] = {1, 5, 10, 50, 100, 500, 1000};

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("preface.in");
	ofstream cout("preface.out");

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp = i;
		for (int p = 1; tmp > 0; p *= 10, tmp /= 10) {
			int remain = tmp % 10;
			remain *= p;
			if (remain != i) {
				for (int j = 0; j < 7; j++) {
					numbers[i][j] += numbers[remain][j];
					ans[j] += numbers[remain][j];
				}
			} else {
				bool is_special = false;
				for (int j = 0; j < 6; j++)
					if (remain == sp_nums[j]) {
						for (int k = 0; k < 7; k++) {
							numbers[i][k] += specials[j][k];
							ans[k] += specials[j][k];
						}
						is_special = true;
						break;
					}
				// if is not a special number
				if (!is_special)
					for (int j = 6; remain > 0; j--) {
						if (chars_num[j] <= remain) {
							numbers[i][j] += remain / chars_num[j];
							ans[j] += remain / chars_num[j];
							remain %= chars_num[j];
						}
					}
			}
		}
	}
	int biggest = 0;
	for (int i = 6; i >= 0; i--)
		if (ans[i]) {
			biggest = i;
			break;
		}

	for (int i = 0; i <= biggest; i++)
		cout << chars[i] << ' ' << ans[i] << endl;

	return 0;
}