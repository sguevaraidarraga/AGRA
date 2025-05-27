/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem A: flight
    Complejidad: O()
    Mayo 22 de 2025
*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>

#define MAX 10000

using namespace std;

int n;
vector<vector<int>> g(MAX);

pair<int, int> centre(set<int> &centre, set<int> &subTreeCentre) {
    int v, maxLevel = 0;
    vector<int> level(n, 0), degree(n);
    queue<int> q;
    for(int i = 0; i < n; i++) degree[i] = g[i].size();
    for(int i = 0; i < n; i++) {
        if(degree[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        v = q.front();
        q.pop();
        for(const int &w : g[v]) {
            degree[w]--;
            if(degree[w] == 0) {
                q.push(w);
                level[w] = level[v]+1;
                maxLevel = max(maxLevel, level[w]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(degree[i] == maxLevel) {
            centre.insert(i);
        }
    }
    int radio = (centre.size() == 2) ? maxLevel+1 : maxLevel, 
        diameter = (centre.size() == 2) ? 2*radio-1 : 2*radio;
    return {radio, diameter};
}
int main() {
    int N, x, y;
    cin >> N;
    while(N--) {
        cin >> n;
        vector<vector<int>> g(n);
        while(n--) {
            cin >> x >> y;
            x--, y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }
    return 0;
}