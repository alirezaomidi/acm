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

	int n, j = 1;
	while (cin >> n) {
		if (n == 0)
			break;
		cout << "Case " << j << ": ";
		cout << setprecision(3) << fixed;
		if (n == 1) {
			double u, v, t;
			cin >> u >> v >> t;
			double a = (v - u) / t;
			double s = .5 * a * t * t + u * t;
			cout << s << ' ' << a;
		} else if (n == 2) {
			double u, v, a;
			cin >> u >> v >> a;
			double t = (v - u) / a;
			double s = .5 * a * t * t + u * t;
			cout << s << ' ' << t;
		} else if (n == 3) {
			double u, a, s;
			cin >> u >> a >> s;
			double v = sqrt(2 * a * s + u * u);
			double t = (v - u) / a;
			cout << v << ' ' << t;
		} else if (n == 4) {
			double v, a, s;
			cin >> v >> a >> s;
			double u = sqrt(v * v - 2 * a * s);
			double t = (v - u) / a;
			cout << u << ' ' << t;
		}
		cout << endl;
		j++;
	}

	return 0;
}
