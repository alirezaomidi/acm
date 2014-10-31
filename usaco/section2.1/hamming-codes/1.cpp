/*
 ID: alireza18
 PROG: hamming
 LANG: C++
 */

#include <fstream>
#include <vector>
using namespace std;

int hamming_distance(int a, int b) {
	int x_or = a ^ b;
	int d = 0;
	while (x_or > 0) {
		if (x_or % 2 == 1)
			d++;
		x_or /= 2;
	}
	return d;
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("hamming.in");
	ofstream cout("hamming.out");

	int number, bits, distance; cin >> number >> bits >> distance;
	vector<int> v;
	int all = 1;
	for (int i = 0; i < bits; i++)
		all *= 2;
	for (int i = 0; i < all; i++) {
		bool ok = true;
		for (int j = 0; j < v.size(); j++)
			if (hamming_distance(v[j], i) < distance) {
				ok = false;
				break;
			}
		if (ok)
			v.push_back(i);
		if (v.size() == number)
			break;
	}
	for (int i = 0, printed = 0; i < v.size() - 1; i++) {
		cout << v[i];
		printed++;
		if (printed == 10) {
			printed = 0;
			cout << endl;
		}
		else if (i < v.size() - 1)
			cout << ' ';
	}
	cout << v[v.size() - 1] << endl;

	return 0;
}