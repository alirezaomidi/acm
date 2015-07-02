#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<string> vs;

vs rotate90(vs& square) {
    int n = square.size();
    vs res(n, string());
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i] += square[n - 1 - j][i];
    return res;
}

int find(vs& small, vs& big) {
    int res = 0;
    int N = big.size(), n = small.size();
    for (int I = 0; I < N - n + 1; I++)
        for (int J = 0; J < N - n + 1; J++)
            if (big[I][J] == small[0][0]) {
                bool found = true;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++)
                        if (big[I + i][J + j] != small[i][j]) {
                            found = false;
                            break;
                        }
                    if (!found)
                        break;
                }
                if (found)
                    res++;
            }
    return res;
}

int main() {
    ios::sync_with_stdio(false);

    int N, n;

    while (cin >> N >> n) {
        if (N == 0 && n == 0)
            break;
        vs big(N, string());
        vs small(n, string());
        for (int i = 0; i < N; i++)
            cin >> big[i];
        for (int i = 0; i < n; i++)
            cin >> small[i];
        for (int i = 0; i < 4; i++) {
            cout << find(small, big);
            if (i != 3) {
                cout << ' ';
                small = rotate90(small);
            }
        }
        cout << endl;
    }

    return 0;
}