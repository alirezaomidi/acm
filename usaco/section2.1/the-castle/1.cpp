/*
 ID: alireza18
 PROG: castle
 LANG: C++
 */

#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int m, n;
vector<vector<pair<int, int> > > nodes; // a 2d array of nodes. pair.first: edges, pair.second: componentNumber
vector<vector<bool> > visited;
vector<int> components; // contains components size

// returns size of component; i: row, j: col
int bfs(int i, int j, int comp_num) {
	int count = 0;
	queue<pair<pair<int, int>, pair<int, int> > > q; // pair.first: node, pair.second: i, j of node
	q.push(make_pair(nodes[i][j], make_pair(i, j)));
	visited[i][j] = true;
	while (!q.empty()) {
		pair<pair<int, int>, pair<int, int> > node = q.front();
		q.pop();
		// visited[node.second.first][node.second.second] = true;
		nodes[node.second.first][node.second.second].second = comp_num;
		count++;
		i = node.second.first;
		j = node.second.second;
		if ((node.first.first & 1) == 1 && j > 0 && !visited[i][j - 1]) {
			q.push(make_pair(nodes[i][j - 1], make_pair(i, j - 1)));
			visited[i][j - 1] = true;
		}
		if ((node.first.first & 2) == 2 && i > 0 && !visited[i - 1][j]) {
			q.push(make_pair(nodes[i - 1][j], make_pair(i - 1, j)));
			visited[i - 1][j] = true;
		}
		if ((node.first.first & 4) == 4 && j < m - 1 && !visited[i][j + 1]) {
			q.push(make_pair(nodes[i][j + 1], make_pair(i, j + 1)));
			visited[i][j + 1] = true;
		}
		if ((node.first.first & 8) == 8 && i < n - 1 && !visited[i + 1][j]) {
			q.push(make_pair(nodes[i + 1][j], make_pair(i + 1, j)));
			visited[i + 1][j] = true;
		}
	}
	return count;
}

int count_comp() {
	int count = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!visited[i][j]) {
				int size = bfs(i, j, count);
				components.push_back(size);
				count++;
			}
	return count;
}

int main() {
	ifstream fin("castle.in");
	ofstream fout("castle.out");

	fin >> m >> n;
	for (int i = 0; i < n; ++i) {
		nodes.push_back(vector<pair<int, int> >());
		visited.push_back(vector<bool>());
		for (int j = 0; j < m; ++j) {
			int edges;
			fin >> edges;
			nodes[i].push_back(make_pair(15 - edges, -1));
			visited[i].push_back(false);
		}
	}

	fout << count_comp() << endl;
	int max = 0;
	for (int i = 0; i < components.size(); ++i)
		if (max < components[i])
			max = components[i];
	fout << max << endl;

	int node_i, node_j, max_size = 0;
	char dir;
	for (int j = 0; j < m; ++j) {
		for (int i = n - 1; i >= 0; --i) {
			if ((nodes[i][j].first & 2) != 2 && i > 0) {
				if (nodes[i][j].second != nodes[i - 1][j].second
						&& components[nodes[i][j].second]
								+ components[nodes[i - 1][j].second]
								> max_size) {
					node_i = i;
					node_j = j;
					dir = 'N';
					max_size = components[nodes[i][j].second]
							+ components[nodes[i - 1][j].second];
				}
			} else if ((nodes[i][j].first & 4) != 4 && j < m - 1) {
				if (nodes[i][j].second != nodes[i][j + 1].second
						&& components[nodes[i][j].second]
								+ components[nodes[i][j + 1].second]
								> max_size) {
					node_i = i;
					node_j = j;
					dir = 'E';
					max_size = components[nodes[i][j].second]
							+ components[nodes[i][j + 1].second];
				}
			}
		}
	}

	fout << max_size << endl;
	fout << node_i + 1 << ' ' << node_j + 1 << ' ' << dir << endl;

	return 0;
}
