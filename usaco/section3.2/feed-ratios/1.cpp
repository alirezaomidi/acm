/*
ID: alireza18
PROG: ratios
LANG: C++
*/

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int calc(int i, int j, int k, int index, vector<vi>& ratios) {
	return i * ratios[0][index] + j * ratios[1][index] + k * ratios[2][index];
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("ratios.in");
	ofstream cout("ratios.out");

	vi goal_ratios(3, 0);
	int goals_sum = 0;
	for (int i = 0; i < 3; i++) {
		cin >> goal_ratios[i];
		goals_sum += goal_ratios[i];
	}

	if (goals_sum == 0) {
		cout << "0 0 0 0" << endl;
		return 0;
	}

	vector<vi> ratios(3, vi(3, 0));
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> ratios[i][j];

	vector<vi> results;
	vi result_ratios(3, 0);
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			for (int k = 0; k < 100; k++) {
				for (int l = 0; l < 3; l++)
					result_ratios[l] = calc(i, j, k, l, ratios);
				bool ok = true;
				int divisor = -1;
				for (int l = 0; l < 3; l++) {
					if (goal_ratios[l] == 0) {
						if (result_ratios[l] != 0) {
							ok = false;
							break;
						}
					} else {
						if (result_ratios[l] % goal_ratios[l] != 0) {
							ok = false;
							break;
						}
						if (divisor == -1)
							divisor = result_ratios[l] / goal_ratios[l];
						else if (result_ratios[l] / goal_ratios[l] != divisor) {
							ok = false;
							break;
						}
					}
				}
				if (ok) {
					vi ans;
					int sum = 0;
					for (int l = 0; l < 3; l++)
						sum += result_ratios[l];
					if (sum == 0) continue;
					ans.push_back(sum);
					ans.push_back(i); ans.push_back(j); ans.push_back(k);
					ans.push_back(result_ratios[0] / goal_ratios[0]);
					results.push_back(ans);
				}
			}

	if (results.size() == 0)
		cout << "NONE" << endl;
	else {
		sort(results.begin(), results.end());
		cout << (*results.begin())[1];
		for (int i = 2; i < 5; i++)
			cout << ' ' << (*results.begin())[i];
		cout << endl;
	}

	return 0;
}