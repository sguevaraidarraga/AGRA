/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B: bit
    Febrero 5 de 2025
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define debug(x) cout << #x << ": " << x

void printMat(vector<vector<char>> &m) {
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            cout << m[i][j];
        }
    }
    cout << endl;
}
string BtoD(vector<vector<char>> &b, int i, int j, int n, int m) {
    string ans;
    if(n == 1 && m == 1) {
        ans = b[i][j];
    }
    else if(n == 1 && m != 1) {
        string s1 = BtoD(b, i, j, n, ceil(m/2.0));
        string s2 = BtoD(b, i, j+ceil(m/2.0), n, floor(m/2.0));
        (s1 == s2) ? ans = s1 : ans = 'D' + s1 + s2;
    }
    else if(n != 1 && m == 1) {
        string s1 = BtoD(b, i, j, ceil(n/2.0), m);
        string s2 = BtoD(b, i+ceil(n/2.0), j, floor(n/2.0), m);
        (s1 == s2) ? ans = s1 : ans = 'D' + s1 + s2;
    }
    else {
        string s1 = BtoD(b, i, j, ceil(n/2.0), ceil(m/2.0));
        string s2 = BtoD(b, i, j+ceil(m/2.0), ceil(n/2.0), floor(m/2.0));
        string s3 = BtoD(b, i+ceil(n/2.0), j, floor(n/2.0), ceil(m/2.0));
        string s4 = BtoD(b, i+ceil(n/2.0), j+ceil(m/2.0), floor(n/2.0), floor(m/2.0));
        (s1 == s2 && s2 == s3 && s3 == s4) ? ans = s1 : ans = 'D' + s1 + s2 + s3 + s4;
    }
    return ans;
}
void DtoB(string &s, vector<vector<char>> &b, int i, int j, int n, int m, int &d) {
    if(d < s.size()) {
        if(s[d] == 'D') {
            d++;
            if(n == 1 && m != 1) {
                DtoB(s, b, i, j, n, ceil(m/2.0), d);
                DtoB(s, b, i, j+ceil(m/2.0), n, floor(m/2.0), d);
            }
            else if(n != 1 && m == 1) {
                DtoB(s, b, i, j, ceil(n/2.0), m, d);
                DtoB(s, b, i+ceil(n/2.0), j, floor(n/2.0), m, d);
            }
            else {
                DtoB(s, b, i, j, ceil(n/2.0), ceil(m/2.0), d);
                DtoB(s, b, i, j+ceil(m/2.0), ceil(n/2.0), floor(m/2.0), d);
                DtoB(s, b, i+ceil(n/2.0), j, floor(n/2.0), ceil(m/2.0), d);
                DtoB(s, b, i+ceil(n/2.0), j+ceil(m/2.0), floor(n/2.0), floor(m/2.0), d);
            }
        }
        else {
            for(int a = i; a < n+i; a++) {
                for(int k = j; k < m+j; k++) {
                    b[a][k] = s[d];
                }
            }
            d++;
        }
    }
}
int main() {
    int rows, columns, i;
    char c, v;
    string l;
    while(cin >> c && c != '#') {
        cin >> rows >> columns;
        vector<vector<char>> bitmap(rows, vector<char>(columns));
        printf("%c %4d %4d\n", (c == 'B' ? 'D' : 'B'), rows, columns);
        if(c == 'B') {
            for(int i = 0; i < bitmap.size(); i++) {
                for(int j = 0; j < bitmap[i].size(); j++) {
                    cin >> v;
                    bitmap[i][j] = v;
                }
            }
            cout << BtoD(bitmap, 0, 0, rows, columns) << endl;
        }
        else if(c == 'D') {
            cin.ignore();
            getline(cin, l);
            i = 0;
            DtoB(l, bitmap, 0, 0, rows, columns, i);
            printMat(bitmap);
        }
    }
    return 0;
}