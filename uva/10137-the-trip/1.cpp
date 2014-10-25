#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define MAX_STDS 1000

double round_within_one_hundredth(double d) {
	return floor(d * 100 + 0.5) / 100;
}

int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	while (n) {
		double pays[MAX_STDS];
		double sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> pays[i];
			sum += pays[i];
		}

		double avg = sum / n;
		double round_avg = round_within_one_hundredth(avg);
		double pos_exchange = 0, neg_exchange = 0;
		for (int i = 0; i < n; ++i) {
			if (pays[i] > round_avg)
				pos_exchange += pays[i] - round_avg;
			else
				neg_exchange += round_avg - pays[i];
		}

		cout << "$";
		if (pos_exchange > neg_exchange)
			cout << fixed << setprecision(2) << neg_exchange;
		else
			cout << fixed << setprecision(2) << pos_exchange;
		cout << endl;

		cin >> n;
	}

	return 0;
}