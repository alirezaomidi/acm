#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> vb;
typedef pair<int, int> ii;

ii next(ii pos, int dir) {
    ii res = pos;
    switch (dir) {
        case 0:
            res.first++;
            break;
        case 1:
            res.second--;
            break;
        case 2:
            res.first--;
            break;
        case 3:
            res.second++;
            break;
    }
    return res;
}

bool corner(ii pos, int n) {
    if (pos == ii(0, 0) || pos == ii(0, n - 1) || pos == ii(n - 1, 0))
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    long long p;
    while (cin >> n >> p) {
        if (n == 0 && p == 0)
            break;
        int spiral_num = 1;
        while (p > (long long)spiral_num * spiral_num) {
            spiral_num += 2;
        }
        long long cur_num = ((long long)spiral_num - 2) * (spiral_num - 2) + 1;
        ii cur_pos = ii(spiral_num - 1, spiral_num - (spiral_num == 1 ? 1 : 2));
        int dir = 1; // left
        while (cur_num < p) {
            cur_pos = next(cur_pos, dir);
            if (corner(cur_pos, spiral_num))
                ++dir %= 4;
            cur_num++;
        }
        cur_pos.first += (n - spiral_num) / 2;
        cur_pos.second += (n - spiral_num) / 2;
        cout << "Line = " << cur_pos.first + 1 << ", column = " << cur_pos.second + 1 << '.' << endl;
    }

    return 0;
}