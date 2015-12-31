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

int main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		ll sumofsqures = (n * (n + 1) * (2 * n + 1)) / 6;
		ll sum = (n * (n + 1)) / 2;
		ll squareofsums = sum * sum;
		cout << abs(sumofsqures - squareofsums) << endl;
	}

	return 0;
}
