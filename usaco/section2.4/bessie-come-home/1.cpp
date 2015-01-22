/*
ID: alireza18
PROG: comehome
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <set>
#include <map>
using namespace std;

const int MAX = 52;
const int inf = 0xfffffff;

int adj[MAX][MAX];
int dist[MAX];
bool visited[MAX];
map<char, int> mp1;
map<int, char> mp2;
set<int> avail;

pair<char, int> dijkstra(int src) {
	for (int i = 0; i < MAX; i++)
		dist[i] = inf;
	dist[src] = 0;
	set<int> st;
	st.insert(src);
	visited[src] = true;
	while (st.size() < avail.size()) {
		int closest_node, min_path = inf;
		for (set<int>::iterator i = st.begin(); i != st.end(); i++)
			for (int j = 0; j < MAX; j++)
				if (adj[*i][j] && !visited[j] && min_path > dist[*i] + adj[*i][j]) {
					min_path = dist[*i] + adj[*i][j];
					closest_node = j;
				}
		st.insert(closest_node);
		visited[closest_node] = true;
		dist[closest_node] = min_path;
		for (int i = 0; i < MAX; i++)
			if (i != closest_node && adj[closest_node][i] && dist[i] > dist[closest_node] + adj[closest_node][i])
				dist[i] = dist[closest_node] + adj[closest_node][i];
	}
	// for (int i = 0; i < MAX; i++)
	// 	cerr << dist[i] << endl;
	pair<char, int> ret; ret.second = inf;
	for (int i = 26; i < MAX; i++)
		if (i != src && dist[i] < ret.second)
			ret = make_pair(mp2[i], dist[i]);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("comehome.in");
	ofstream cout("comehome.out");

	
	for (char c = 'a'; c <= 'z'; c++) {
		mp1[c] = c - 'a';
		mp2[c - 'a'] = c;
	}
	for (char c = 'A'; c <= 'Z'; c++) {
		mp1[c] = c - 'A' + 26;
		mp2[c - 'A' + 26] = c;
	}

	int paths; cin >> paths;
	while (paths--) {
		char a_char, b_char;
		int c;
		cin >> a_char >> b_char >> c;
		int a = mp1[a_char], b = mp1[b_char];
		avail.insert(a); avail.insert(b);
		if (!adj[a][b] || adj[a][b] > c) {
			adj[a][b] = c;
			adj[b][a] = c;
		}
	}

	pair<char, int> ans = dijkstra(mp1['Z']);
	cout << ans.first << ' ' << ans.second << endl;

	return 0;
}