/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem C: fredericton
    Complejidad: O()
    Abril 9 de 2025
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>

#define INF 1e9
using namespace std;

int n;
vector<vector<pair<int, int>>> g(250);
vector<vector<int>> dist(250, vector<int>(250));

void bfm() {
    int v, w;
    dist[0][0] = 0;
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 0; j < n; j++) {
            dist[i][j] = dist[i-1][j];
        }
        for(int u = 0; u < n; u++) {
            for(int j = 0; j < g[u].size(); j++) {
                v = g[u][j].first, w = g[u][j].second;
                if(dist[i-1][u] != INF && dist[i-1][u] + w < dist[i-1][v]) {
                    dist[i][v] = dist[i-1][u] + w;
                }
            }
        }
    }
}
int main() {
    int cases, m, a, b, c, q;
    string city, city2;
    cin >> cases;
    for(int i = 1; i <= cases; i++) {
        cin >> n;
        map<string, int> cities;
        for(int i = 0; i < n; i++) {
            cin >> city;
            cities[city] = i;
        }
        cin >> m;
        while(m--) {
            cin >> city >> city2 >> c;
            a = cities[city], b = cities[city2];
            g[a].push_back({b, c});
        }
        bfm();
        cin >> q;
        cout << "Scenario #" << i << endl;
        while(q--) {
            cin >> a;
            if(dist[a+1][n-1] == INF) {
                cout << "No satisfactory flights" << endl;
            }
            else {
                cout << "Total cost of flight(s) is $" << dist[a+1][n-1] << endl;
            }            
        }
        cout << endl;
        g.assign(n, vector<pair<int, int>>());
        dist.assign(n, vector<int>(n, INF));
    }
    return 0;
}