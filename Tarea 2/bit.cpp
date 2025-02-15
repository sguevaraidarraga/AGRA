/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B: bit
    Febrero 5 de 2025
*/

/*
    - If all bits within it are 1, a ’1’ is output.
    - If all bits within it are 0, a ’0’ is output.
    - Otherwise, a D is output.

    - Quarters processing: top left, top right, bottom left, bottom right.

    - Even # of rows and columns -> all quarters have the same dimentions.
    - Otherwise, odd # of columns -> left quarters have columns+1.
                 odd # of rows -> top quarters have rows+1.

    - Note that if a region having only one row or one column is divided then two halves result, with the top half processed before the bottom where a single column is divided, and the left half before the right if a single row is divided.
*/

#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout << #x << ": " << x << endl

void printBM(vector<vector<int>> &bm, int l1, int h1, int l2, int h2) {
    for(int i = l1; i <= h1; i++) {
        cout << '[';
        for(int j = l2; j <= h2; j++) {
            cout << bm[i][j];
            if(j != h2) {
                cout << ", ";
            }
        }
        cout << ']' << endl;
    }
}
int BtoD(vector<vector<int>> &bm, int low1, int high1, int low2, int high2, int depth) {
    int ans, mid1 = (low1+high1)/2, mid2 = (low2+high2)/2, v1, v2, v3, v4;
    bool f = false;
    debug(low1), debug(mid1), debug(high1);
    debug(low2), debug(mid2), debug(high2);
    printBM(bm, low1, high1, low2, high2);
    debug((low1 == high1 && low2 == high2));
    if(low1 == high1 || low2 == high2) {
        ans = bm[low1][low2];
        debug(ans);
        f = true;
    }
    if(!f) {
        v1 = BtoD(bm, low1, mid1, low2, mid2, depth+1);
        v2 = BtoD(bm, low1, mid1, mid2+1, high2, depth+1);
        v3 = BtoD(bm, mid1+1, high1, low2, mid2, depth+1);
        v4 = BtoD(bm, mid1+1, high1, mid2+1, high2, depth+1);
        cout << "Divisiones: "<< v1 << v2 << v3 << v4 << endl;
        if(depth > 0) {
            cout << "  => D";
        }
        if(v1 == v2 == v3 == v4) {
            cout << v1;
        }
        else {
            cout << v1 << v2 << v3 << v4;
        }
        cout << endl;
    }
    return ans;
}
int main() {
    char v, c;
    int v2, rows, columns;
    while(cin >> c && c != '#') {
        cin >> rows >> columns;
        if(c == 'B') {
            vector<vector<int>> bitmap(rows, vector<int>(columns));
            for(int i = 0; i < bitmap.size(); i++) {
                for(int j = 0; j < bitmap[i].size(); j++) {
                    cin >> v;
                    v2 = v - '0';
                    bitmap[i][j] = v2;
                }
            }
            //printBM(bitmap);
            BtoD(bitmap, 0, rows-1, 0, columns-1, 0);
        }
        else if(c == 'D') {

        }
        printf("%c %4d %4d", (c == 'B' ? 'D' : 'B'), rows, columns);
    }
    return 0;
}