/*
ID: alireza18
PROG: ttwo
LANG: C++
*/

#include <fstream>
#include <map>
#include <climits>
using namespace std;

#define SIZE 10

typedef pair<int, int> ii;

enum Dirs {UP, RIGTH, DOWN, LEFT};
enum Types {EMPTY, OBSTACLE, COW, FARMER};

int board[SIZE][SIZE];
ii cowpos;
ii farmerpos;
int dirs[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
const int x = 0, y = 1;

bool is_in_range(ii pos, int dir) {
	if (pos.first + dirs[dir][x] < 0 || pos.first + dirs[dir][x] >= SIZE
		|| pos.second + dirs[dir][y] < 0 || pos.second + dirs[dir][y] >= SIZE)
		return false;
	return true;
}

bool is_in_front_of_obstacle(ii pos, int dir) {
	if (board[pos.first + dirs[dir][x]][pos.second + dirs[dir][y]] == OBSTACLE)
		return true;
	return false;
}

void move(ii& pos, int dir) {
	pos.first += dirs[dir][x];
	pos.second += dirs[dir][y];
}

void rotate(int& dir) {
	++dir %= 4;
}

int ans() {
	int cowdir = UP, farmerdir = UP;
	int time = 0;
	while (cowpos != farmerpos) {

		if (is_in_range(cowpos, cowdir) && !is_in_front_of_obstacle(cowpos, cowdir))
			move(cowpos, cowdir);
		else
			rotate(cowdir);

		if (is_in_range(farmerpos, farmerdir) && !is_in_front_of_obstacle(farmerpos, farmerdir))
			move(farmerpos, farmerdir);
		else
			rotate(farmerdir);

		if (time < INT_MAX / 100)
			time++;
		else
			return 0;
	}
	return time;
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("ttwo.in");
	ofstream cout("ttwo.out");

	map<char, int> mp;
	mp['.'] = EMPTY; mp['*'] = OBSTACLE;
	mp['C'] = COW; mp['F'] = FARMER;

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++) {
			char c; cin >> c;
			board[j][i] = mp[c];
			if (c == 'C')
				cowpos = make_pair(j, i);
			else if (c == 'F')
				farmerpos = make_pair(j, i);
		}

	cout << ans() << endl;

	return 0;
}