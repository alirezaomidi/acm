/*
ID: alireza18
PROG: numtri
LANG: C++
*/

#include <fstream>
#include <vector>
using namespace std;

// returns max sum of itself and its children
int dfs(vector< vector< pair<int, int> > >& v, int& rows, int row, int col) {
	if (row == rows - 1)
		return v[row][col].first;
	if (v[row][col].second != -1)
		return v[row][col].second;
	v[row][col].second = v[row][col].first + max(dfs(v, rows, row + 1, col), dfs(v, rows, row + 1, col + 1));
	return v[row][col].second;
}

int main() {
	ios::sync_with_stdio(false);
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");

	int rows;
	fin >> rows;

	// pair.first = num; pair.second = max of itself and its children
	vector< vector< pair <int, int> > > v(rows);

	for (int cRow = 0; cRow < rows; ++cRow)
		for (int cNum = 0; cNum < cRow + 1; ++cNum) {
			int num;
			fin >> num;
			v[cRow].push_back(make_pair(num, -1));
		}

	fout << dfs(v, rows, 0, 0) << endl;

	return 0;
}
