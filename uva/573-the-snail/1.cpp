#include <iostream>
using namespace std;

int simulate(int h, float u, int d, int f, bool& success) {
    float fatique = f / 100. * u;
    float cur = 0;
    int day = 0;
    while (cur <= h && cur >= 0) {
        day++;
        if (u - fatique >= 0) {
            cur += u;
            if (cur > h) {
                success = true;
                break;
            }
        }
        cur -= d;
        if (cur < 0) {
            success = false;
            break;
        }
        u -= fatique;
    }
    return day;
}

int main() {
    ios::sync_with_stdio(false);

    int h, u, d, f;
    while (cin >> h >> u >> d >> f) {
        if (h == 0) break;
        bool success;
        int day = simulate(h, u, d, f, success);
        cout << (success ? "success" : "failure") << " on day " << day << endl;
    }

    return 0;
}