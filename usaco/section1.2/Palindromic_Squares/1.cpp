/*
ID: alireza18
PROG: palsquare
LANG: C++
*/

#include <fstream>
#include <string>
using namespace std;

void rev(string& s) {
    for (int i = 0; i < s.length() / 2; ++i) {
        swap(s[i], s[s.length() - 1 - i]);
    }
}

string toBase(int n, int b) {
    string s;
    while (n > 0) {
        if (n % b < 10) {
            s += n % b + '0';
        } else {
            s += (n % b - 10) + 'A';
        }
        n /= b;
    }
    rev(s);
    return s;
}

bool isPalin(string s) {
    for (int i = 0; i < s.length() / 2; ++i) {
        if (s[i] != s[s.length() - 1 - i])
            return false;
    }
    return true;
}

int main () {
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");

    int base;
    fin >> base;

    for (int i = 1; i <= 300; ++i) {
        if (isPalin(toBase(i * i, base))) {
            fout << toBase(i, base) << " " << toBase(i * i, base) << endl;
        }
    }

    return 0;
}
