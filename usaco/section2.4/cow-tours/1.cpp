/*
ID: alireza18
PROG: cowtour
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;

#define MAX 150
const int inf = INT_MAX;
int n;
int adj[MAX][MAX];
double fl_war[MAX][MAX];
int coor[MAX][2];

void floyd_warshall() {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				fl_war[i][j] = min(fl_war[i][j], fl_war[i][k] + fl_war[k][j]);
}

double getdist(int *a, int *b) {
	return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
}

int main() {
	ios::sync_with_stdio(false);
	ifstream cin("cowtour.in");
	FILE *cout = fopen("cowtour.out", "w");

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> coor[i][0] >> coor[i][1];

	for (int i = 0; i < n; i++) {
		cin.get();
		for (int j = 0; j < n; j++) {
			char c; cin.get(c);
			adj[i][j] = c - '0';
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && adj[i][j] != 1)
				adj[i][j] = inf;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (adj[i][j] == 1)
				fl_war[i][j] = getdist(coor[i], coor[j]);
			else
				fl_war[i][j] = adj[i][j];
		}

	floyd_warshall();

	double ans = (double)inf;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j || fl_war[i][j] != inf) continue;
			double largest_i = 0, largest_j = 0;
			for (int k = 0; k < n; k++) {
				if (fl_war[i][k] != inf && largest_i < fl_war[i][k])
					largest_i = fl_war[i][k];
				if (fl_war[j][k] != inf && largest_j < fl_war[j][k])
					largest_j = fl_war[j][k];
			}
			double tmp = largest_i + largest_j + getdist(coor[i], coor[j]);
			if (ans > tmp)
				ans = tmp;
		}

	double maxx = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (fl_war[i][j] != inf && fl_war[i][j] > maxx)
				maxx = fl_war[i][j];

	if (maxx > ans)
		ans = maxx;
	fprintf(cout, "%.6lf\n", ans);

	return 0;
}