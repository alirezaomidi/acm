#include <fstream>
#include <string>
using namespace std;

string pad[8] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};

string gen(string input) {
    if (input.length() == 0) {
        check(res);
        res.pop_back();
        input--;
    }
    static string res;
    int i = 0;
    while (i++ < 3) {
        res += pad[(int)(input[0] - '0') - 2][i];
        input++;
        gen(input);
    }
}

int main() {
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    string input;
    cin >> input;
    int len = input.length();

    gen(input);

    return 0;
}
