#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    vector<unsigned int> v;
    unsigned int a;
    while (cin >> a) {
        v.push_back(a);
        nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
        if (v.size() % 2)
            cout << v[v.size() / 2];
        else {
            nth_element(v.begin(), v.begin() + v.size() / 2 - 1, v.end());
            cout << (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2;
        }
        cout << endl;
    }

    return 0;
}