/*
ID: alireza18
PROG: concom
LANG: C++
*/

#include <fstream>
#include <set>
using namespace std;

#define MAX 100

int n;
int share[MAX][MAX];
bool controls[MAX][MAX];

typedef set< pair<int, int> > st;
st ans;

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("concom.in");
	ofstream cout("concom.out");

	int triples; cin >> triples;
	while (triples--) {
		int a, b, p; cin >> a >> b >> p;
		if (n < a)
			n = a;
		if (n < b)
			n = b;
		a--; b--;
		share[a][b] = p;
		if (p > 50)
			controls[a][b] = true;
	}

	for (int i = 0; i < n; i++)
		controls[i][i] = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (controls[i][j]) {
				ans.insert(make_pair(i, j));
				continue;
			}
			int sh = 0;
			for (int k = 0; k < n; k++)
				if (controls[i][k])
					sh += share[k][j];
			if (sh > 50) {
				controls[i][j] = true;
				ans.insert(make_pair(i, j));
				j = -1;
			}
		}
	}

	for (st::iterator i = ans.begin(); i != ans.end(); i++)
		cout << i->first + 1 << ' ' << i->second + 1 << endl;

	return 0;
}