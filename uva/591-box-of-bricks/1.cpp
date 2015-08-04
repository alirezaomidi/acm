#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iomanip>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;

const int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);

    int n, j = 1;
    while (cin >> n) {
        if (n == 0)
            break;
        vi v(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }

        int minn = 0;
        int avg = sum / n;

        for (int i = 0; i < n; i++)
            if (v[i] > avg)
                minn += v[i] - avg;

        cout << "Set #" << j << endl;
        cout << "The minimum number of moves is " << minn << '.' << endl;
        cout << endl;
        j++;
    }

	return 0;
}
