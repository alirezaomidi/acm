#include <iostream>
#include <fstream>

using namespace std;

int vote[20];
bool isin[20];
int ans[20];
int partyCount;
int allsum, sum;

void check() {
	for (int i = 0; i < partyCount; i++) {
		if (!isin[i] && sum <= allsum / 2) {
			if (vote[i] + sum > allsum / 2)
				ans[i]++;
		}
	}
}

void calcCoal (int i){
	if (i == partyCount) {
		check();
		return;
	}
	isin[i] = 0;
	calcCoal(i + 1);
	isin[i] = 1;
	sum += vote[i];
	calcCoal(i + 1);
	sum -= vote[i];
}

void clear() {
	for (int i = 0; i < partyCount; i++)
		ans[i] = 0;
	sum = 0;
}

int main(){
	int testcase; cin >> testcase;
	while (testcase--){
		cin >> partyCount;

		allsum = 0;
		for (int i = 0; i < partyCount; ++i)
		{
			cin >> vote[i];
			allsum += vote[i];	
		}

		clear();
		calcCoal(0);

		for (int i = 0; i < partyCount; i++) {
			cout << "party " << i + 1 << " has power index " << ans[i] << endl;
		}
		cout << endl;
	}

	return 0;
}