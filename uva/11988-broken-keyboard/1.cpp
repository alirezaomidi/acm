#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string s;
    while (cin >> s) {
        list<char> text;
        list<char>::iterator it = text.end();
        bool home = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[') {
                home = true;
                it = text.begin();
            } else if (s[i] == ']') {
                home = false;
                it = text.end();
            } else {
                if (home) {
                    text.push_front(s[i]);
                    home = false;
                } else
                    text.insert(it, s[i]);
            }
        }
        for (it = text.begin(); it != text.end(); it++)
            cout << *it;
        cout << endl;
    }

    return 0;
}