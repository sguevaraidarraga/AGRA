/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem C: war
    Complejidad: O(1) Amort
    Mayo 22 de 2025
*/

#include <iostream>
#include <vector>

#define MAX 20000

using namespace std;

int n;
vector<int> p(MAX), s(MAX);

void makeSet(int i) {
    p[i] = i, s[i] = 0;
}
int find(int x) {
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}
void unionSet(int x, int y) {
    x = find(x), y = find(y);
    if(x != y) {
        if(s[x] < s[y]) swap(x, y);
        p[y] = x;
        if(s[x] == s[y]) s[x]++;
    }
}
bool areFriends(int x, int y) {
    return find(x) == find(y);
}
int main() {
    int c, x, y;
    bool f;
    while(cin >> n) {
        for(int i = 0; i < 2*n; i++) makeSet(i);
        f = false;
        while(!f) {
            cin >> c >> x >> y;
            if(c == 0 && x == 0 && y == 0) {
                f = true;
            } else {
                if(c == 1) {
                    if(areFriends(x, y+n)) {
                        cout << -1 << endl;
                    } else {
                        unionSet(x, y);
                        unionSet(x+n, y+n);
                    }
                }
                else if(c == 2) {
                    if(areFriends(x, y)) {
                        cout << -1 << endl;
                    } else {
                        unionSet(x, y+n);
                        unionSet(x+n, y);
                    }
                }
                else if(c == 3) {
                    cout << areFriends(x, y) << endl;
                }
                else if(c == 4) {
                    cout << areFriends(x, y+n) << endl;
                }
            }
        }
    }
}