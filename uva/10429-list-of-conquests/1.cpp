#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	map<string, int> ans;
	int n; cin >> n;
	while (n--) {
		string tmp, country; cin >> country;
		getline(cin, tmp);
		ans[country]++;
	}

	for (map<string, int>::iterator i = ans.begin(); i != ans.end(); i++)
		cout << i->first << ' ' << i->second << endl;

	return 0;
}