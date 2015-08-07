#include <iostream>
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
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;

const int inf = 1e9;

int main() {
	// ios::sync_with_stdio(false);

	string m;
	while (getline(cin, m)) {
		if (m == "#")
			break;
		int crc = 0, g = 34943;
		for (int i = 0; i < m.size(); i++) {
			crc <<= 8;
			(crc += m[i]) %= g;
		}
		crc = ((ll)crc << 16) % g;
		crc = (g - crc) % g;

		// C++ Style
		// cout << hex << uppercase << setfill('0')
		// << setw(2) << (crc >> 8)
		// << ' '
		// << setw(2) << (crc % 256)
		// << endl;

		// C Style (much more better!)
		printf("%02X %02X\n", crc >> 8, crc % 256);
	}

	return 0;
}
