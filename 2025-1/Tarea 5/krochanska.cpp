/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem D: krochanska
    Complejidad: O(nlog n)
    Abril 3 de 2025
*/

#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9
using namespace std;

int n;
vector<vector<int>> g;
vector<int> imp;

int bfs(int s) {
    int ans = 0, u, v;
    queue<int> q;
    vector<int> dist(n+1, INF);
    dist[s] = 0;
    q.push(s);
    while(!q.empty()) {
        v = q.front();
        q.pop();
        for(int i = 0; i < g[v].size(); i++) {
            u = g[v][i];
            if(dist[u] == INF) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    for(int i = 0; i < imp.size(); i++) {
        ans += dist[imp[i]];
    }
    return ans;
}
int main() {
    int cases, s, at, to;
    double av, mav;
    cin >> cases;
    while(cases--) {
        cin >> n >> s;
        g.assign(n+1, vector<int>());
        vector<int> cnt(n+1, 0);
        while(s--) {
            cin >> at;
            cnt[at]++;
            while(cin >> to && to != 0) {
                g[at].push_back(to);
                g[to].push_back(at);
                cnt[to]++;
                at = to;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(cnt[i] > 1) imp.push_back(i);
        }
        mav = INF;
        for(int i = 0; i < imp.size(); i++) {
            av = bfs(imp[i]);
            if(av < mav) {
                mav = av;
                at = imp[i];
            }
            if(av == mav) at = min(at, imp[i]);
        }
        cout << "Krochanska is in: " << at << endl;
        g.clear();
        imp.clear();
    }
    return 0;
}