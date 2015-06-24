#include <iostream>
#include <vector>

using namespace std;

int rev(int n) {
    int ret = 0;
    while (n > 0) {
        ret = 10 * ret + (n % 10);
        n /= 10;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    vector <bool> isPrime (1000000 , true);

    isPrime[0] = false; isPrime[1] = false;
    for (int i = 2; i <= 1000; i++) {
        if (!isPrime[i]) continue;
        for (int j = i + i; j < 1000000; j += i) {
            isPrime[j] = false;
        }
    }

    int n;
    while (cin >> n) {
        if (isPrime[n] && isPrime[rev(n)] && n != rev(n))
            cout << n << " is emirp.";
        else if (isPrime[n])
            cout << n << " is prime.";
        else
            cout << n << " is not prime.";
        cout << endl;
    }

    return 0;
}
