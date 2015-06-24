#include <iostream>
#include <string>
using namespace std;

void print_num(const string& num, int size) {
	for (int row = 0; row < 2 * size + 3; ++row) { // iterate on rows
		for (int digit = 0; digit < num.length(); ++digit) { // iterate on digits
			if (row == 0 || row == size + 1 || row == 2 * size + 2) {
				cout << ' ';
				switch (num[digit]) { // for 2,3,5,6,8,9 fill all of the row segments
					case '2':
					case '3':
					case '5':
					case '6':
					case '8':
					case '9':
						for (int i = 0; i < size; ++i) cout << '-';
						break;
				}
				// for 0,1,4,7
				if (row == 0) {
					switch (num[digit]) { // first row
						case '0':
						case '7':
							for (int i = 0; i < size; ++i) cout << '-';
							break;
						case '1':
						case '4':
							for (int i = 0; i < size; ++i) cout << ' ';
							break;
					}
				} else if (row == size + 1) { // mid row
					switch (num[digit]) {
						case '0':
						case '1':
						case '7':
							for (int i = 0; i < size; ++i) cout << ' ';
							break;
						case '4':
							for (int i = 0; i < size; ++i) cout << '-';
							break;
					}
				} else if (row == 2 * size + 2) { // last row
					switch (num[digit]) {
						case '1':
						case '4':
						case '7':
							for (int i = 0; i < size; ++i) cout << ' ';
							break;
						case '0':
							for (int i = 0; i < size; ++i) cout << '-';
							break;
					}
				} // end of 0,1,4,7

				cout << ' ';
			} else {
				if (0 < row && row < size + 1) {
					switch (num[digit]) {
						case '0':
						case '4':
						case '5':
						case '6':
						case '8':
						case '9':
							cout << '|';
							break;
						default:
							cout << ' ';
							break;
					}
					for (int i = 0; i < size; ++i) cout << ' ';
					switch (num[digit]) {
						case '0':
						case '1':
						case '2':
						case '3':
						case '4':
						case '7':
						case '8':
						case '9':
							cout << '|';
							break;
						default:
							cout << ' ';
							break;
					}
				} else {
					switch (num[digit]) {
						case '0':
						case '2':
						case '6':
						case '8':
							cout << '|';
							break;
						default:
							cout << ' ';
							break;
					}
					for (int i = 0; i < size; ++i) cout << ' ';
					if (num[digit] == '2')
						cout << ' ';
					else
						cout << '|';
				}
			}
			if (digit < num.length() - 1) // column of blanks
				cout << ' ';
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	int s; string n;
	cin >> s >> n;
	while (s) {
		print_num(n, s);
		cout << endl;
		cin >> s >> n;
	}

	return 0;
}