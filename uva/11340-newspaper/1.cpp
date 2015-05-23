#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int chars_count; cin >> chars_count;

        map<char, int> values;
        for (int i = 0; i < chars_count; i++) {
            char c; int a;
            cin >> c >> a;
            values[c] = a;
        }

        int lines; cin >> lines;
        int money = 0;

        cin.ignore();
        while (lines--) {
            string line;
            getline(cin, line);
            for (int i = 0; i < line.length(); i++)
                money += values[line[i]];
        }

        cout << setprecision(2) << fixed << (double)money / 100 << '$' << endl;
    }

    return 0;
}