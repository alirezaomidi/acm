#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);

    int s, b;
    while (cin >> s >> b) {
        if (s == 0 && b == 0) break;

        vi left, right;
        for (int i = 0; i < s; i++) {
            left.push_back(i - 1);
            right.push_back(i + 1);
        }
        right[s - 1] = -1;

        for (int i = 0; i < b; i++) {
            int l, r; cin >> l >> r;
            l--; r--;

            if (right[r] != -1)
                left[right[r]] = left[l];
            if (left[l] != -1)
                right[left[l]] = right[r];

            if (left[l] != -1)
                cout << left[l] + 1 << ' ';
            else
                cout << "* ";

            if (right[r] != -1)
                cout << right[r] + 1 << endl;
            else
                cout << '*' << endl;
        }
        cout << '-' << endl;
    }


    return 0;
}