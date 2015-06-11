/*
ID: alireza18
PROG: butter
LANG: C++
*/

#include <fstream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef set< pair<int, int> > sii;
typedef vector< set< pair<int, int> > > vsii;

int cows_n, pastures_n, paths_n;
vi cows;
vsii adj;

int dist[800];
void dijksta(int src) {
    sii q;
    for (int i = 0; i < pastures_n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    q.insert(make_pair(0, src));

    while (!q.empty()) {
        ii top = *q.begin();
        q.erase(q.begin());
        int v = top.second, d = top.first;
        for (sii::iterator it = adj[v].begin(); it != adj[v].end(); it++) {
            int u = it->first, w = it->second;
            if (dist[u] > dist[v] + w) {
                if (dist[u] != INT_MAX)
                    q.erase(q.find(make_pair(dist[u], u)));
                dist[u] = dist[v] + w;
                q.insert(make_pair(dist[u], u));
            }
        }
    }
}

int dist_sum(int src) {
    dijksta(src);
    int res = 0;
    for (int i = 0; i < cows_n; i++)
        res += dist[cows[i]];
    return res;
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("butter.in");
	ofstream cout("butter.out");

    cin >> cows_n >> pastures_n >> paths_n;
    for (int i = 0; i < cows_n; i++) {
        int cow_pasture; cin >> cow_pasture;
        cow_pasture--;
        cows.push_back(cow_pasture);
    }

    for (int i = 0; i < pastures_n; i++)
        adj.push_back(sii());

    for (int i = 0; i < paths_n; i++) {
        int a, b, len; cin >> a >> b >> len;
        a--; b--;
        adj[a].insert(make_pair(b, len));
        adj[b].insert(make_pair(a, len));
    }

    int ans = INT_MAX;
    for (int i = 0; i < pastures_n; i++)
        ans = min(ans, dist_sum(i));

    cout << ans << endl;

	return 0;
}