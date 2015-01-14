/*
ID: alireza18
PROG: maze1
LANG: C++
*/

#include <fstream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int cols, rows;
const int inf = 0xfffffff;
int size;
vi adj[4000];
int dist[4000][2];
bool visited[4000];
vi exits;

bool is_out(ii p) {
	if (p.first < 0 || p.first >= rows || p.second < 0 || p.second >= cols)
		return true;
	return false;
}

void bfs(int src, int index) {
	queue<int> q;
	q.push(src);
	visited[src] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < adj[v].size(); i++) {
			int u = adj[v][i];
			if (!visited[u]) {
				q.push(u);
				visited[u] = true;
				dist[u][index] = dist[v][index] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("maze1.in");
	ofstream cout("maze1.out");

	cin >> cols >> rows;
	size = cols * rows;

	for (int i = 0; i < rows * 2 + 1; i++) {
		cin.get();
		for (int j = 0; j < cols * 2 + 1; j++) {
			char c; c = cin.get();
			if (i % 2 == 0 && j % 2 == 0) continue;
			if (i % 2 && j % 2) continue;
			if (c != '-' && c != '|') {
				ii first, second;
				if (i % 2 == 0) {
					first = make_pair(i / 2 - 1, j / 2);
					second = make_pair(i / 2, j / 2);
				} else {
					first = make_pair(i / 2, j / 2 - 1);
					second = make_pair(i / 2, j / 2);
				}
				if (is_out(first))
					exits.push_back(second.first * cols + second.second);
				else if (is_out(second))
					exits.push_back(first.first * cols + first.second);
				else {
					adj[first.first * cols + first.second].push_back(second.first * cols + second.second);
					adj[second.first * cols + second.second].push_back(first.first * cols + first.second);
				}
			}
		}
	}

	int maxx = 0;
	bfs(exits[0], 0);
	for (int i = 0; i < size; i++)
		visited[i] = false;
	bfs(exits[1], 1);
	for (int i = 0; i < size; i++) {
		int minn = min(dist[i][0], dist[i][1]);
		if (minn > maxx)
			maxx = minn;
	}

	cout << maxx + 1 << endl;

	return 0;
}