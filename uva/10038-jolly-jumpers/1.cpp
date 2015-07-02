#include <iostream>
#include <set>
#include <cstdlib>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        int a; cin >> a;
        int b;
        set<int> s;
        bool jolly = true;
        for (int i = 0; i < n - 1; i++) {
            cin >> b;
            int diff = abs(b - a);
            if (diff > 0 && diff < n)
                s.insert(diff);
            else
                jolly = false;
            a = b;
        }
        if (jolly && s.size() == n - 1)
            cout << "Jolly";
        else
            cout << "Not jolly";
        cout << endl;
    }

    return 0;
}