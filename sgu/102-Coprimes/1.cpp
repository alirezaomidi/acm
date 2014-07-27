#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int n, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        if (gcd(n, i) == 1)
            res++;
    cout << res << endl;
            
    return 0;
}
