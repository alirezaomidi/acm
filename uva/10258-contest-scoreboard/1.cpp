#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;

bool compare(pair<ii, int> a, pair<ii, int> b) {
    if (a.first.first > b.first.first)
        return true;
    if (a.first.first < b.first.first)
        return false;
    if (a.first.second < b.first.second)
        return true;
    if (a.first.second > b.first.second)
        return false;
    if (a.second < b.second)
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);

    int t; cin >> t;
    bool first = true;
    while (t--) {
        vector<vi> penalties(101, vi(10, 0));
        vector<vb> solved(101, vb(10, false));
        vb participated(101, false);

        vector< pair<ii, int> > scoreboard; // < <problems solved, penalty >, contestant num >
        for (int i = 0; i <= 100; i++)
            scoreboard.push_back(make_pair(ii(0, 0), i));

        stringstream ss;
        string s;
        if (first) {
            cin.ignore();
            cin.ignore();
        }
        while (getline(cin, s)) {
            if (s.empty()) break;
            ss << s;
            int contestant, problem, submit_time;
            ss >> contestant >> problem >> submit_time;
            char status; ss >> status;
            participated[contestant] = true;
            if (status == 'C') {
                if (!solved[contestant][problem]) {
                    solved[contestant][problem] = true;
                    penalties[contestant][problem] += submit_time;
                }
            } else if (status == 'I')
                if (!solved[contestant][problem])
                    penalties[contestant][problem] += 20;
        }

        for (int i = 0; i <= 100; i++) {
            int penalty = 0, solved_count = 0;
            for (int j = 1; j <= 9; j++)
                if (solved[i][j]) {
                    penalty += penalties[i][j];
                    solved_count++;
                }
            scoreboard[i].first.first = solved_count;
            scoreboard[i].first.second = penalty;
        }

        sort(scoreboard.begin(), scoreboard.end(), compare);

        if (!first)
            cout << endl;
        else
            first = false;

        for (int i = 0; i <= 100; i++) {
            pair<ii, int> score = scoreboard[i];
            if (!participated[score.second])
                continue;
            cout << score.second << ' ' << score.first.first << ' ' << score.first.second << endl;
        }
    }

    return 0;
}