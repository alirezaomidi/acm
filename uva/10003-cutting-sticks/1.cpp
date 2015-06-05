#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> vi;

const int MAX = 50;

int main() {
    ios::sync_with_stdio(false);

    int len, n;
    while (cin >> len) {
        if (len == 0) break;
        cin >> n;
        vi cuts;
        cuts.push_back(0);
        for (int i = 0; i < n; i++) {
            int cut; cin >> cut;
            cuts.push_back(cut);
        }
        cuts.push_back(len);

        n += 2;

        int dp[MAX][MAX]; // dp[i][j] -> minimum cut for interval: ( cuts[i]  cuts[j] )

        for (int i = 0; i < n - 1; i++) {
            dp[i][i] = 0;
            dp[i][i + 1] = 0;
        }

        for (int l = 2; l < n; l++) {
            for (int i = 0; i < n - l; i++) {
                int j = i + l;
                int minn = INT_MAX;
                for (int k = i + 1; k < j; k++)
                    minn = min(minn, dp[i][k] + dp[k][j]);
                dp[i][j] = minn + cuts[j] - cuts[i];
            }
        }

        cout << "The minimum cutting is " << dp[0][n - 1] << '.' << endl;
    }

    return 0;
}