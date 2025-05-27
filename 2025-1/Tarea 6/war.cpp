/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem C: war
    Complejidad: O(1) Amort
    Mayo 23 de 2025
*/

#include <iostream>
#include <vector>

#define MAX 10000

using namespace std;

int n;
vector<int> parent(MAX), enemy(MAX), size(MAX);

void makeSet(int i) {
    parent[i] = i;
    enemy[i] = -1;
    size[i] = 0;
}
int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}
void unionSet(int x, int y) {
    x = find(x), y = find(y);
    if(x != y) {
        if(size[x] < size[y]) swap(x, y);
        parent[y] = x;
        if(size[x] == size[y]) size[x]++;
    }
}
bool setFriends(int x, int y) {
    bool ans = true;
    x = find(x), y = find(y);
    if(x != enemy[y]) {
        unionSet(x, y);
        int ex = enemy[x], ey = enemy[y];
        if(ex != -1 && ey != -1) {
            unionSet(ex, ey);
            enemy[find(x)] = find(ex);
            enemy[find(ex)] = find(x);
        }
        else if(ex != -1) {
            enemy[find(x)] = find(ex);
            enemy[find(ex)] = find(x);
        }
        else if(ey != -1) {
            enemy[find(x)] = find(ey);
            enemy[find(ey)] = find(x);
        }
        ans = false;
    }
    return ans;
}
bool setEnemies(int x, int y) {
    bool ans = true;
    x = find(x), y = find(y);
    if(x != y) {
        if(enemy[x] == -1) {
            enemy[x] = y;
        }
        else {
            unionSet(enemy[x], y);
        }
        if(enemy[y] == -1) {
            enemy[y] = x;
        }
        else {
            unionSet(x, enemy[y]);
        }
        x = find(x), y = find(y);
        enemy[x] = y;
        enemy[y] = x;
        ans = false;
    }
    return ans;
}
bool areFriends(int x, int y) {
    return find(x) == find(y);
}
bool areEnemies(int x, int y) {
    return find(x) == enemy[find(y)];
}
int main() {
    int c, x, y, ans;
    bool f;
    while(cin >> n) {
        for(int i = 0; i < n; i++) makeSet(i);
        f = false;
        while(!f) {
            cin >> c >> x >> y;
            if(c == 0 && x == 0 && y == 0) f = true;
            else {
                ans = 2;
                if(c == 1) {
                    if(setFriends(x, y)) ans = -1;
                }
                else if(c == 2) {
                    if(setEnemies(x, y)) ans = -1;
                }
                else if(c == 3) {
                    ans = areFriends(x, y);
                }
                else if(c == 4) {
                    ans = areEnemies(x, y);
                }
                if(ans != 2) cout << ans << endl;
            }
        }
    }
}
