#include <iostream>
using namespace std;

int grid[5][5], tmpgrid[5][5];

int main() {
    ios::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        for (int i = 1; i < 4; i++)
            for (int j = 1; j < 4; j++) {
                char c; cin >> c;
                grid[i][j] = c - '0';
            }

        int zeros = 0;
        int ans = -1;

        while (true) {
            for (int i = 1; i < 4; i++)
                for (int j = 1; j < 4; j++)
                    if (grid[i][j] == 0) zeros++;

            if (zeros == 9) {
                cout << ans << endl;
                break;
            }

            zeros = 0;
            ans++;

            for (int i = 1; i < 4; i++)
                for (int j = 1; j < 4; j++)
                    tmpgrid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) % 2;

            for (int i = 1; i < 4; i++)
                for (int j = 1; j < 4; j++)
                    grid[i][j] = tmpgrid[i][j];
        }
    }

    return 0;
}