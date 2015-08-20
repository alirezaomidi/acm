#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;

const int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);

    ll n;
    while (cin >> n) {
        if (n == 0) break;
        ll sqr = sqrt(n) + 1;
        bool square = false;
        for (ll i = 2; i <= sqr; i++) {
            if (i * i == n) {
                square = true;
                break;
            }
        }
        if (square || n == 1) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

	return 0;
}
