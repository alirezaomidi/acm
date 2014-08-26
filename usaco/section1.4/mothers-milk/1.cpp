/*
 ID: alireza18
 PROG: milk3
 LANG: C++
 */

#include <fstream>
#include <vector>
#include <set>
using namespace std;

vector<int> c(3);
vector<int> v(3, 0);
set< vector<int> > states;

// generate all statess
void dfs() {
	if (states.find(v) != states.end())
		return;
	states.insert(v);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			if (i == j)
				continue;
			if (v[i] > 0 && c[j] - v[j] > 0)  {
				// now we cat pour
				int p = min(v[i], c[j] - v[j]);
				v[i] -= p; v[j] += p;
				dfs();
				v[i] += p; v[j] -= p; // backtrack
			}
		}
}

int main() {
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");

	for (int i = 0; i < 3; ++i)
		fin >> c[i];
	v[2] = c[2];

	dfs();

	set<int> res;
	// choose those which A=0
	for (set< vector<int> >::iterator i = states.begin(); i != states.end(); ++i)
		if ((*i)[0] == 0)
			res.insert((*i)[2]);
	// print sorted set
	for (set<int>::iterator i = res.begin(); *i != *res.rbegin(); ++i)
		fout << *i << ' ';
	fout << *res.rbegin() << endl;

	return 0;
}
