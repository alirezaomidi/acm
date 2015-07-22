#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        if (n == 0) break;

        vi coaches;
        for (int i = 0; i < n; i++)
            coaches.push_back(i + 1);

        while (true) {
            bool ok = true;
            vi goal;
            for (int i = 0; i < n; i++) {
                int a; cin >> a;
                if (a == 0) {
                    ok = false;
                    break;
                }
                goal.push_back(a);
            }

            if (!ok)
                break;

            stack<int> s;

            int i = 0, j = 0; // i for coaches, j for goal
            while (j < n) {
                if (!s.empty() && s.top() == goal[j]) {
                    j++;
                    s.pop();
                } else if (i < n)
                    s.push(coaches[i++]);
                else
                    break;
            }
            if (j == n)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        cout << endl;
    }

    return 0;
}