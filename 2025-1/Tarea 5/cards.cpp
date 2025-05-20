/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem A: cards
    Complejidad: O((p + q)log p)
    Abril 3 de 2025
*/

#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9
using namespace std;

int p;

int dijkstra(vector<vector<pair<int, int>>> &g) {
    int ans = 0, u, v, du, dv;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(p+1, INF);
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()) {
        du = pq.top().first, u = pq.top().second;
        pq.pop();
        if(du <= dist[u]) {
            for(int i = 0; i < g[u].size(); i++) {
                v = g[u][i].first, dv = g[u][i].second;
                if(du+dv < dist[v]) {
                    dist[v] = du+dv;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    for(int i = 2; i <= p; i++) {
        ans += dist[i];
    }
    return ans;
}
int main() {
    int cases, q, a, b, d;
    cin >> cases;
    while(cases--) {
        cin >> p >> q;
        vector<vector<pair<int, int>>> g(p+1), gt(p+1);
        while(q--) {
            cin >> a >> b >> d;
            g[a].push_back({b, d});
            gt[b].push_back({a, d});
        }
        cout << dijkstra(g) + dijkstra(gt) << endl;
    }
    return 0;
}