// using bitset

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

typedef vector<int> vi;

const int max_bits = 15;

int main() {
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        vi weights(1 << n, 0);
        vi potencies;
        for (int i = 0; i < 1 << n; i++)
            cin >> weights[i];
        for (int i = 0; i < 1 << n; i++) {
            bitset<max_bits> neighbour(i);
            int potency = 0;
            for (int j = 0; j < n; j++) {
                neighbour.flip(j);
                potency += weights[neighbour.to_ulong()];
                neighbour.flip(j);
            }
            potencies.push_back(potency);
        }
        int max_sum = 0;
        for (int i = 0; i < 1 << n; i++) {
            bitset<max_bits> neighbour(i);
            for (int j = 0; j < n; j++) {
                neighbour.flip(j);
                max_sum = max(max_sum, potencies[i] + potencies[neighbour.to_ulong()]);
                neighbour.flip(j);
            }
        }
        cout << max_sum << endl;
    }

    return 0;
}