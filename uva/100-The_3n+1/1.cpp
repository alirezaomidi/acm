#include <iostream>
using namespace std;

int cycleLength(int n) {
    if (n == 1)
        return 1;
    return 1 + cycleLength(n % 2 == 0 ? n / 2 : 3 * n + 1);
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        int max = 0;
        cout << a << ' ' << b << ' ';
        if (a > b)
            swap(a, b);
        for (int i = a; i <= b; i++) {
            int len = cycleLength(i);
            if (len > max)
                max = len;
        }
        cout << max << endl;
    }
    return 0;
}
