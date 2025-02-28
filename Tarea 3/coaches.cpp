/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem A: coaches
    Febrero 28 de 2025
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Coach {
    string name;
    int birth;
    vector<int> coached;
    vector<int> wasCoached;
    Coach(string n, int y) {
        name = n;
        birth = y;
        coached = wasCoached = vector<int>();
    }
};
int main() {
    int cases, n, m, y, c1, c2;
    string a, b;
    cin >> cases;
    while(cases--) {
        cin >> n >> m;
        vector<Coach> g(n);
        for(int i = 0; i < n; i++) {
            cin >> a >> y;
            mp[a] = make_pair(i, y);
        }
        while(m--) {
            cin >> a >> b;
            c1 = mp[a].first, c2 = mp[b].first;
            g[c1].
        }
    }
    return 0;
}