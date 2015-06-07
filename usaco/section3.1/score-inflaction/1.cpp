/*
ID: alireza18
PROG: inflate
LANG: C++
*/

#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10000;

int max_val[MAX + 1];

typedef pair<int, int> ii;
typedef vector< pair<int, int> > vii;

vii cats; // worth, time

double get_fract_worth(ii cat) {
	return (double)cat.first / cat.second;
}

bool compare(ii a, ii b) {
	double a_worth = get_fract_worth(a);
	double b_worth = get_fract_worth(b);
	if (a_worth > b_worth)
		return true;
	else if (a_worth < b_worth)
		return false;
	if (a.second < b.second)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("inflate.in");
	ofstream cout("inflate.out");


	int contest_time, categories; cin >> contest_time >> categories;
	for (int i = 0; i < categories; i++) {
		int worth, time; cin >> worth >> time;
		cats.push_back(make_pair(worth, time));
	}

	sort(cats.begin(), cats.end(), compare);

	for (int i = 1; i <= contest_time; i++)
		for (int j = 0; j < categories; j++) {
			if (i >= cats[j].second) {
				max_val[i] = max(max_val[i], max_val[i - cats[j].second] + cats[j].first);
			}
		}

	cout << max_val[contest_time] << endl;

	return 0;
}
