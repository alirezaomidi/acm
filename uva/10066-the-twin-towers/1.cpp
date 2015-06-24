#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int LCS[101][101];

int main() {
    ios::sync_with_stdio(false);

    int n1, n2, count = 1;
    while (cin >> n1 >> n2) {
        if (n1 == 0 && n2 == 0) break;
        for (int  i = 0 ; i <= n1 ; i++){
            for (int j = 0; j <= n2 ; j++) {
                LCS[i][j] = 0;
            }
        }
        vi a(n1, 0), b(n2, 0);
        for (int i = 0; i < n1; i++)
            cin >> a[i];
        for (int i = 0; i < n2; i++)
            cin >> b[i];


        for (int  i = 1 ; i <= n1 ; i++){
            for (int j = 1; j <= n2 ; j++) {
                if (a[i - 1] == b[j - 1]){
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                }
                else {
                    LCS[i][j] = max (LCS[i-1][j] , LCS[i][j-1]);
                }
            }
        }

        cout << "Twin Towers #" << count << endl;
        cout << "Number of Tiles : " << LCS[n1][n2] << endl << endl;
        count++;


    }

    return 0;
}
