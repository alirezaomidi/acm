#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string s;
    while (cin >> s) {
        if (s == "#") break;
        if (next_permutation(s.begin(), s.end()))
            cout << s;
        else
            cout << "No Successor";
        cout << endl;
    }

    return 0;
}