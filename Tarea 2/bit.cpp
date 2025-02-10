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

void printBM(vector<vector<char>> &bm) {
    for(int i = 0; i < bm.size(); i++) {
        cout << '[';
        for(int j = 0; j < bm[i].size(); j++) {
            cout << bm[i][j];
            if(j != bm[i].size()-1) {
                cout << ", ";
            }
        }
        cout << ']' << endl;
    }
}
void BtoD(vector<vector<char>> &bm, int n1, int n2, int m1, int m2) {
    int mid1 = (n1+n2)/2, mid2 = (m1+m2)/2;
    cout << "rows: " << mid1 << endl;
    cout << "columns: " << mid2 << endl;
    cout << (mid1 != 1 && mid2 != 1) << endl;
    if(mid1 != 1 && mid2 != 1) {
        BtoD(bm, 0, mid1, 0, mid2);
        BtoD(bm, mid1, n2, mid2, m2);
        BtoD(bm, 0, mid1, 0, mid2);
        BtoD(bm, mid1, n2, mid2, m2);
    }
}
int main() {
    char v, c;
    int rows, columns;
    while(cin >> c && c != '#') {
        cin >> rows >> columns;
        if(c == 'B') {
            vector<vector<char>> bitmap(rows, vector<char>(columns));
            for(int i = 0; i < bitmap.size(); i++) {
                for(int j = 0; j < bitmap[i].size(); j++) {
                    cin >> v;
                    bitmap[i][j] = v;
                }
            }
            printBM(bitmap);
            BtoD(bitmap, 0, rows, 0, columns);
        }
        else if(c == 'D') {

        }
        printf("%c %4d %4d", (c == 'B' ? 'D' : 'B'), rows, columns);
    }
    return 0;
}