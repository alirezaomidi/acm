#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		int n; cin >> n;
		int maxx = 0;
		while (n--) {
			int tmp; cin >> tmp;
			maxx = max(maxx, tmp);
		}
		cout << "Case " << i << ": " << maxx << endl;
	}

	return 0;
}