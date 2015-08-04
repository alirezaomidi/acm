#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;

const int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);

	int n;
	bool first = true;
	while (cin >> n) {
		if (!first)
			cout << endl;
		else
			first = false;

		int sum = 0;
		for (int i = 1; i < n; i++)
			sum += floor(sqrt(abs(((2 * n - 1) / 2.) * ((2 * n - 1) / 2.) - i * i)));
		sum *= 4;

		cout << "In the case n = " << n << ", " << 8 * (n - 1) + 4 << " cells contain segments of the circle." << endl;
		cout << "There are " << sum << " cells completely contained in the circle." << endl;
	}

	return 0;
}
