#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, b, h, w;
	while (cin >> n >> b >> h >> w) {
		int ans = b;
		while (h--) {
			int price; cin >> price;
			for (int i = 0; i < w; i++) {
				int beds; cin >> beds;
				if (beds >= n) {
					ans = min(ans, price * n);
				}
			}
		}
		if (ans != b)
			cout << ans << endl;
		else
			cout << "stay home" << endl;
	}


	return 0;
}