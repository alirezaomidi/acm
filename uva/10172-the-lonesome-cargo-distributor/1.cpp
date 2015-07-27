#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
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

	int t; cin >> t;
	while (t--) {
		int n, ssize, qsize; cin >> n >> ssize >> qsize;
		vector< queue<int> > qs(n, queue<int>());
		int tofinish = 0;
		for (int i = 0; i < n; i++) {
			int count; cin >> count;
			tofinish += count;
			while (count--) {
				int tmp; cin >> tmp;
				qs[i].push(tmp);
			}
		}

		stack<int> s;
		int finished = 0;
		int ans = 0;
		for (int i = 0; finished < tofinish; (++i) %= n) {
			// unload
			while (!s.empty()) {
				if (s.top() - 1 == i)
					finished++;
				else {
					if (qs[i].size() < qsize)
						qs[i].push(s.top());
					else
						break;
				}
				s.pop();
				ans++;
			}
			// load
			while (s.size() < ssize && !qs[i].empty()) {
				s.push(qs[i].front());
				qs[i].pop();
				ans++;
			}

			if (finished < tofinish)
				ans += 2;
		}
		cout << ans << endl;
	}

	return 0;
}