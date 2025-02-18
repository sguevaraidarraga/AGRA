/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B: bit
    Febrero 5 de 2025
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define debug(x) cout << #x << ": " << x

void printLine(string &s) {
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(cnt == 50) {
            cout << endl;
            cnt = 0;
        }
        cout << s[i];
        cnt++;
    }
    cout << endl;
}
void printMat(vector<vector<char>> &m) {
    int cnt = 0;
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            if(cnt == 50) {
                cout << endl;
                cnt = 0;
            }
            cout << m[i][j];
            cnt++;
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
    char c, no;
    bool f;
    cin >> c;
    while(c != '#') {
        cin >> rows >> columns;
        string l;
        f = false;
        (c == 'D' ? no = 'D' : no = '\0');
        while(cin >> c) {
            if(c != '#' || c != no) {
                l += c;
                f = true;
            }
        }
        vector<vector<char>> bitmap(rows, vector<char>(columns));
        printf("%c %3d %3d\n", (c == 'B' ? 'D' : 'B'), rows, columns);
        if(c == 'B') {
            i = 0;
            for(int j = 0; j < rows; j++) {
                for(int k = 0; k < columns; k++) {
                    bitmap[j][k] = l[i];
                    i++;
                }
            }
            l = BtoD(bitmap, 0, 0, rows, columns);
            printLine(l);
        }
        else if(c == 'D') {
            DtoB(l, bitmap, 0, 0, rows, columns, i = 0);
            printMat(bitmap);
        }
    }
    return 0;
}