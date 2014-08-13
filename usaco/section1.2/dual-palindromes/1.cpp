/*
ID: alireza18
PROG: dualpal
LANG: C++
*/
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

bool checkPal(string n) {
    if (n[0] == '0' || n[n.length() - 1] == '0')
        return false;
    for (int i = 0; i < n.length() / 2; i++)
        if (n[i] != n[n.length() - 1 - i])
            return false;
    return true;
}

string toBase(int n, int b) {
    string res;
    while (n > 0) {
        res += n % b;
        n /= b;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    int n, s;
    fin >> n >> s;

    int j = 0;
    for (int i = s + 1; j < n; i++) {
        int count = 0;
        for (int b = 2; b <= 10; b++) {
            if (checkPal(toBase(i, b)))
                count++;
            if (count >= 2) {
                fout << i << endl;
                j++;
                break;
            }
        }
    }

    return 0;
}
