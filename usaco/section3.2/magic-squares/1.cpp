/*
ID: alireza18
PROG: msquare
LANG: C++
*/

#include <fstream>
#include <queue>
#include <set>
#include <string>
using namespace std;

typedef vector<int> vi;

vi A(vi& v) {
	vi res(v);
	for (int i = 0; i < 4; i++)
		swap(res[i], res[7 - i]);
	return res;
}

vi B(vi& v) {
	vi res(v);
	int tmp = res[3];
	for (int i = 3; i > 0; i--)
		res[i] = res[i - 1];
	res[0] = tmp;
	tmp = res[4];
	for (int i = 4; i < 7; i++)
		res[i] = res[i + 1];
	res[7] = tmp;
	return res;
}

vi C(vi& v) {
	vi res(v);
	int tmp = res[1];
	res[1] = res[6];
	res[6] = res[5];
	res[5] = res[2];
	res[2] = tmp;
	return res;
}

string bfs(vi& v, vi& target) {
	queue<vi> q;
	q.push(v);
	queue<string> strs;
	strs.push("");
	set<vi> visited;
	visited.insert(v);
	while (!q.empty()) {
		if (q.front() == target)
			return strs.front();

		vi a = A(q.front());
		vi b = B(q.front());
		vi c = C(q.front());

		if (visited.find(a) == visited.end()) {
			q.push(a);
			strs.push(strs.front() + "A");
			visited.insert(a);
		}
		if (visited.find(b) == visited.end()) {
			q.push(b);
			strs.push(strs.front() + "B");
			visited.insert(b);
		}
		if (visited.find(c) == visited.end()) {
			q.push(c);
			strs.push(strs.front() + "C");
			visited.insert(c);
		}
		q.pop();
		strs.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("msquare.in");
	ofstream cout("msquare.out");

	vi v, target(8, 0);
	for (int i = 1; i <= 8; i++) {
		v.push_back(i);
		cin >> target[i - 1];
	}

	string ans = bfs(v, target);
	cout << ans.length() << endl << ans << endl;

	return 0;
}