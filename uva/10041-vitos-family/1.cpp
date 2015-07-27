#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int v[501];
int freq[30002];

int main() {
    ios::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int r; cin >> r;
        for (int i = 0; i < r; i++)
            cin >> v[i];
        sort(v, v + r);

        for (int i = v[0]; i <= v[r - 1]; i++)
            freq[i] = 0;
        for (int i = 0; i < r; i++)
            freq[v[i]]++;

        int g = r - freq[v[0]], l = freq[v[0]];
        int sum = 0;
        for (int i = 0; i < r; i++)
            sum += abs(v[i] - v[0]);

        int minn = sum;
        for (int i = v[0] + 1; i <= v[r - 1]; i++) {
            sum += l;
            sum -= g;
            minn = min(minn, sum);
            g -= freq[i];
            l += freq[i];
        }
        cout << minn << endl;
    }

    return 0;
}