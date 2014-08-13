/*
 ID: alireza18
 PROG: namenum
 LANG: C++
 */

#include <fstream>
#include <string>
#include <map>
using namespace std;

int main() {
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");

	map<char, char> pad;
	for (char c = 'A'; c <= 'P'; ++c)
		pad[c] = '2' + (c - 'A') / 3;
	for (char c = 'Q'; c <= 'Y'; ++c)
		pad[c] = '7' + (c - 'Q') / 3;

	string num;
	fin >> num;

	ifstream dict("dict.txt");
	string s;
	bool isNone = true;
	while (dict >> s) {
		string tmp;
		for (string::iterator itr = s.begin(); itr != s.end(); ++itr) {
			if (*itr == ('Q' | 'Z')) {
				tmp.clear();
				break;
			}
			tmp += pad[*itr];
		}
		if (tmp == num) {
			fout << s << endl;
			isNone = false;
		}
	}
	if (isNone)
		fout << "NONE" << endl;

	return 0;
}
