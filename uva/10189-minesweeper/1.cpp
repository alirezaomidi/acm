#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	int t = 1;
	while (n && m) {
		string field[n + 2];
		// initializing first and last rows
		for (int i = 0; i < m + 2; ++i) {
			field[0] += ".";
			field[n + 1] += ".";
		}
		// initializing other rows
		for (int i = 1; i <= n; ++i) {
			field[i] = ".";
			string tmp; cin >> tmp;
			field[i] += tmp;
			field[i] += ".";
		}

		int dirs[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
		cout << "Field #" << t << ":" << endl;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (field[i][j] == '.') {
					int num = 0;
					for (int k = 0; k < 8; ++k)
						if (field[i + dirs[k][0]][j + dirs[k][1]] == '*')
							num++;
					field[i][j] = num + '0';
				}
				cout << field[i][j];
			}
			cout << endl;
		}

		cin >> n >> m;
		if (n && m)
			cout << endl;
		t++;
	}

	return 0;
}