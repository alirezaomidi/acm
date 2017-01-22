#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

const int inf = 1e9;

bool all_green(vi& lights, int t) {
	for (auto light : lights) {
		int time_in_this_light = t % (2 * light);
		if (time_in_this_light >= light - 5) // red or orange
			return false;
		// else green
	}
	return true;
}

int main() {
//	ios::sync_with_stdio(false);

	int first, second;
	while (cin >> first >> second && first && second) {
		vi lights;
		lights.push_back(first);
		lights.push_back(second);

		int light;
		while (cin >> light && light)
			lights.push_back(light);

		int first_orange = *min_element(lights.begin(), lights.end()) - 5;
		int i;
		for (i = first_orange; i <= 18000; i++)
			if (all_green(lights, i))
				break;
		if (i <= 18000)
			printf("%02d:%02d:%02d\n", i / 3600, (i % 3600) / 60, i % 60);
		else
			puts("Signals fail to synchronise in 5 hours");
	}

	return 0;
}
