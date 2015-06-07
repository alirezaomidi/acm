/*
ID: alireza18
PROG: agrinet
LANG: C++
*/

#include <fstream>
#include <set>
using namespace std;

const int MAX = 100;

int parent[MAX];

void init_disjoint_set(int size) {
	for (int i = 0; i < size; i++)
		parent[i] = i;
}

int _find(int node) {
	if (parent[node] == node)
		return node;
	return parent[node] = _find(parent[node]);
}

void _union(int a, int b) {
	parent[_find(a)] = parent[_find(b)];
}

int mat[MAX][MAX];

typedef pair<int, int> ii;
typedef pair< int, pair<int, int> > iii;

iii make_iii(int w, int a, int b) {
	return make_pair(w, make_pair(a, b));
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("agrinet.in");
	ofstream cout("agrinet.out");

	set<iii> adj_list;

	int farms; cin >> farms;
	for (int i = 0; i < farms; i++)
		for (int j = 0; j < farms; j++) {
			cin >> mat[i][j];
			adj_list.insert(make_iii(mat[i][j], i, j));
		}

	init_disjoint_set(farms);
	
	int mst_weight = 0;
	for (set<iii>::iterator i = adj_list.begin(); i != adj_list.end(); i++) {
		ii current = i->second;
		if (_find(current.first) != _find(current.second)) {
			_union(current.first, current.second);
			mst_weight += i->first;
		}
	}

	cout << mst_weight << endl;

	return 0;
}