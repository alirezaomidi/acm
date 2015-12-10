#include <bits/stdc++.h>

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
typedef pair<double, double> dd;

const int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);

	vi seq;
	int tmp;
	while (cin >> tmp)
		seq.push_back(tmp);

	vi l(seq.size()), l_index(seq.size()), suc(seq.size());
	int lis = 0, lis_end = 0;
	for (int i = 0; i < seq.size(); i++) {
	    int pos = lower_bound(l.begin(), l.begin() + lis, seq[i]) - l.begin();
	    l[pos] = seq[i];
	    l_index[pos] = i;
	    suc[i] = pos ? l_index[pos - 1] : -1;
	    if (pos + 1 > lis) {
	        lis = pos + 1;
	        lis_end = i;
	    }
	}

	cout << lis << endl << '-' << endl;

	stack<int> s;
	int i;
	for (i = lis_end; suc[i] >= 0; i = suc[i])
	    s.push(seq[i]);

	cout << seq[i] << endl;
	while (!s.empty()) {
	    cout << s.top() << endl;
	    s.pop();
	}

	return 0;
}
