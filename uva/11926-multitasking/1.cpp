#include <iostream>
#include <bitset>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;
        bitset<(int)1e6 + 1> minutes;
        bool conflict = false;
        for (int i = 0; i < n; i++) {
            int start, end; cin >> start >> end;
            for (int j = start + 1; j <= end; j++) {
                if (minutes[j])
                    conflict = true;
                else
                    minutes.set(j);
            }
        }
        for (int i = 0; i < m; i++) {
            int start, end, interval; cin >> start >> end >> interval;
            while (start <= 1e6) {
                for (int j = start + 1; j <= end; j++) {
                    if (minutes[j])
                        conflict = true;
                    else
                        minutes.set(j);
                }
                start += interval;
                end = min((int)1e6, end + interval);
            }
        }
        if (conflict)
            cout << "CONFLICT" << endl;
        else
            cout << "NO CONFLICT" << endl;
    }

    return 0;
}