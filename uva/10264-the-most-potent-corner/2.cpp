// using bitmasks

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        vi weights(1 << n, 0);
        vi potencies;
        for (int i = 0; i < 1 << n; i++)
            cin >> weights[i];
        for (int i = 0; i < 1 << n; i++) {
            int potency = 0;
            for (int j = 0; j < n; j++)
                potency += weights[i ^ (1 << j)];
            potencies.push_back(potency);
        }
        int max_sum = 0;
        for (int i = 0; i < 1 << n; i++)
            for (int j = 0; j < n; j++)
                max_sum = max(max_sum, potencies[i] + potencies[i ^ (1 << j)]);
        cout << max_sum << endl;
    }

    return 0;
}