/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem D - cakey
    Enero 24 de 2025
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n, m, val;
    while(cin >> n >> m && n != 0 && m != 0) {
        vector<int> nVal(n), mVal(m);
        for(int i = 0; i < n; i++) {
            cin >> val;
            nVal[i] = val;
        }
        for(int i = 0; i < m; i++) {
            cin >> val;
            mVal[i] = val;
        }
    }
    return 0;
}