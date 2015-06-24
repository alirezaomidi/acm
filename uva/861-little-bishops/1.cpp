#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

vector<vi> k_bishops(int n, int k, vi& cells) {
    vector<vi> res(n + 1, vi(k + 1, 0));
    for (int i = 0; i <= n; i++)
        res[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k && j <= i; j++)
            res[i][j] = res[i - 1][j] + res[i - 1][j - 1] * (cells[i - 1] - (j - 1));
    return res;
}

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
        vi black_cells, white_cells;
        int diags = 2 * n - 1;
        for (int i = 0; i < diags; i++)
            (i % 2 ? white_cells : black_cells).push_back(i < n ? i + 1 : diags - i);
        sort(black_cells.begin(), black_cells.end());
        sort(white_cells.begin(), white_cells.end());
        vector<vi> black = k_bishops(n, k, black_cells);
        vector<vi> white = k_bishops(n - 1, k, white_cells);
        long long ans = 0;
        for (int i = 0; i <= k; i++)
            ans += black[n][i] * white[n - 1][k - i];
        cout << ans << endl;
    }

    return 0;
}