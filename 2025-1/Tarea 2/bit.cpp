/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B: bit
    Complejidad: O(Log n) donde n = ab/10**-10
    Febrero 18 de 2025
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

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
    else {
        string tl, tr, bl, br;
        int ceilN = (n+1)/2, floorN = n/2, ceilM = (m+1)/2, floorM = m/2;
        if(n == 1 && m != 1) {
            tl = BtoD(b, i, j, n, ceilM);
            tr = BtoD(b, i, j+ceilM, n, floorM);
            ans = (tl == tr) ? tl : 'D' + tl + tr;
        }
        else if(n != 1 && m == 1) {
            tl = BtoD(b, i, j, ceilN, m);
            bl = BtoD(b, i+ceilN, j, floorN, m);
            ans = (tl == bl) ? tl : 'D' + tl + bl;
        }
        else {
            tl = BtoD(b, i, j, ceilN, ceilM);
            tr = BtoD(b, i, j+ceilM, ceilN, floorM);
            bl = BtoD(b, i+ceilN, j, floorN, ceilM);
            br = BtoD(b, i+ceilN, j+ceilM, floorN, floorM);
            ans = (tl == tr && tr == bl && bl == br && br == tl) ? tl : 'D' + tl + tr + bl + br;
        }
    }
    return ans;
}
void DtoB(string &s, vector<vector<char>> &b, int i, int j, int n, int m, int &d) {
    int ceilN = (n+1)/2, floorN = n/2, ceilM = (m+1)/2, floorM = m/2;
    if(s[d] == 'D') {
        if(d < s.size()) {
            d++;
            if(n == 1 && m != 1) {
                DtoB(s, b, i, j, n, ceilM, d);
                DtoB(s, b, i, j+ceilM, n, floorM, d);
            }
            else if(n != 1 && m == 1) {
                DtoB(s, b, i, j, ceilN, m, d);
                DtoB(s, b, i+ceilN, j, floorN, m, d);
            }
            else {
                DtoB(s, b, i, j, ceilN, ceilM, d);
                DtoB(s, b, i, j+ceilM, ceilN, floorM, d);
                DtoB(s, b, i+ceilN, j, floorN, ceilM, d);
                DtoB(s, b, i+ceilN, j+ceilM, floorN, floorM, d);
            }
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
int main() {
    int rows, columns, i;
    string cmd;
    cin >> cmd;
    while(cmd != "#") {
        string s, l, ans;
        cin >> rows >> columns >> l;
        while(l != "D" && l != "B" && l != "#") {
            s += l;
            cin >> l;
        }
        vector<vector<char>> bitmap(rows, vector<char>(columns));
        printf("%c %3d %3d\n", (cmd[0] == 'B' ? 'D' : 'B'), rows, columns);
        if(cmd[0] == 'B') {
            i = 0;
            for(int j = 0; j < rows; j++) {
                for(int k = 0; k < columns; k++) {
                    bitmap[j][k] = s[i];
                    i++;
                }
            }
            ans = BtoD(bitmap, 0, 0, rows, columns);
            printLine(ans);
        }
        else if(cmd[0] == 'D') {
            DtoB(s, bitmap, 0, 0, rows, columns, i = 0);
            printMat(bitmap);
        }
        cmd = l;
    }
    return 0;
}