/*
ID: alireza18
PROG: fact4
LANG: C++
*/

#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> vi;

const int mod = 1e6;

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("fact4.in");
	ofstream cout("fact4.out");

	int n; cin >> n;

	vi facts;
	facts.push_back(1);

	for (int i = 1; i <= n; i++) {
		int fact = i * facts.back();
		while (fact % 10 == 0)
			fact /= 10;
		facts.push_back(fact % mod);
	}

	cout << facts.back() % 10 << endl;

	return 0;
}