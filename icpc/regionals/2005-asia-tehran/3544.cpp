#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
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
	map <char , int> keyPress;
	keyPress[' '] = 1;
	keyPress['A'] = keyPress['B'] = keyPress['C'] = 2;
	keyPress['D'] = keyPress['E'] = keyPress['F'] = 3;
	keyPress['G'] = keyPress['H'] = keyPress['I'] = 4;
	keyPress['J'] = keyPress['K'] = keyPress['L'] = 5;
	keyPress['M'] = keyPress['N'] = keyPress['O'] = 6;
	keyPress['P'] = keyPress['Q'] = keyPress['R'] = keyPress['S'] = 7;
	keyPress['T'] = keyPress['U'] = keyPress['V'] = 8;
	keyPress['W'] = keyPress['X'] = keyPress['Y'] = keyPress['Z'] = 9;

	map <char , int> pressTime;
	pressTime['A'] = pressTime['D'] = pressTime['G'] = pressTime['J'] = pressTime['M'] = pressTime['P'] =
	pressTime['T'] = pressTime['W'] = 1;
	pressTime['B'] = pressTime['E'] = pressTime['H'] = pressTime['K'] = pressTime['N'] = pressTime['Q'] =
	pressTime['U'] = pressTime['X'] = 2;
	pressTime['C'] = pressTime['F'] = pressTime['I'] = pressTime['L'] = pressTime['O'] = pressTime['R'] =
	pressTime['V'] = pressTime['Y'] = 3;
	pressTime['S'] = pressTime['Z'] = 4;
	pressTime[' '] = 1;

	int test;
	cin >> test;
	while (test--){
		int press; int wait; cin >> press >> wait;
		cin.get();
		string text;
		getline (cin , text);
		int t = 0;
		int prevKey = -1;
		for (int i = 0 ;i < text.size() ; i++){
			int curKey = keyPress[text[i]];
			int keyTime = pressTime[text[i]];
			if (curKey == prevKey && text[i] != ' '){
				t += wait;
			}
			t += keyTime * press;
			prevKey = curKey;
		}
		cout << t << endl;
	}


	return 0;
}
