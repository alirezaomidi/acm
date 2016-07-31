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

	int n; cin >> n;
	while (n--) {
		int l; cin >> l;
		vi train(l, 0);
		for (int i = 0; i < l; i++)
			cin >> train[i];

		// bubble sort
		int ans = 0;
		for (int i = 0; i < l; i++)
			for (int j = i + 1; j < l; j++)
				if (train[i] > train[j]) {
					ans++;
					swap(train[i], train[j]);
				}
		cout << "Optimal train swapping takes " << ans << " swaps." << endl;
	}

	return 0;
}
