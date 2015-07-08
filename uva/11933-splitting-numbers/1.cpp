#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    unsigned int n;
    while (cin >> n) {
        if (n == 0)
            break;
        int a = 0, b = 0;
        for (unsigned int i = 0, j = 1; (1 << i) <= n; i++)
            if (n & (1 << i)) {
                if (j++ % 2)
                    a += 1 << i;
                else
                    b += 1 << i;
            }
        cout << a << ' ' << b << endl;
    }

    return 0;
}