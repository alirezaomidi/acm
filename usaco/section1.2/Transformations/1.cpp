/*
ID: alireza18
PROG: transform 
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

int n;

bool transform(int p, char **sqBefore, char **sqAfter) {
    switch (p) {
        case 1: {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (sqBefore[i][j] != sqAfter[j][n - i - 1])
                        return false;
            return true;
            break;
        }
        case 2: {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (sqBefore[i][j] != sqAfter[n - i - 1][n - j - 1])
                        return false;
            return true;
            break;
        }
        case 3: {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (sqBefore[j][n - i - 1] != sqAfter[i][j])
                        return false;
            return true;
            break;
        }
        case 4: {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (sqBefore[i][j] != sqAfter[i][n - j - 1])
                        return false;
            return true;
            break;
        }
        case 5: {
            char **tmp = new char*[n];
                for (int i = 0; i < n; ++i)
                    tmp[i] = new char[n];

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    tmp[i][n - j - 1] = sqBefore[i][j];
            if (transform(1, tmp, sqAfter) || transform(2, tmp, sqAfter) || transform(3, tmp, sqAfter))
                return true;
            return false;
            break;
        }
        case 6: {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (sqBefore[i][j] != sqAfter[i][j])
                        return false;
            return true;
            break;
        }
    }
}

int main() {
    ifstream fin("transform.in");
    ofstream fout("transform.out");

    fin >> n;

    char **sqBefore = new char*[n];
    char **sqAfter = new char*[n];

    for (int i = 0; i < n; ++i) {
        sqBefore[i] = new char[n];
        sqAfter[i] = new char[n];
    }

    for (int i = 0; i < n; ++i)
       for (int j = 0; j < n; ++j)
           fin >> sqBefore[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            fin >> sqAfter[i][j];

    for (int i = 1; i <= 6; ++i)
        if (transform(i, sqBefore, sqAfter)) {
            fout << i << endl;
            return 0;
        }

    fout << 7 << endl;
    return 0;
}
