#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Edge {
    int u, v, w;
    Edge() = default;
    Edge(int x, int y, int c) : u(x), v(y), w(c) {if(v < u) swap(u, v);}
    bool operator<(const Edge &b) const {return w < b.w;}
};

int n, total;
vector<Edge> edges;
vector<int> treeId(50000);
vector<Edge> mst;
set<pair<int, int>> s;

void kruskal() {
    int u, v, p1, p2;
    for(int i = 0; i < n; ++i) treeId[i] = i;
    sort(edges.begin(), edges.end());
    for(vector<Edge>::iterator it = edges.begin(); it != edges.end(); it++) {
        u = it->u, v = it->v;
        if(!s.count({min(u, v), max(u, v)})) {
            if(treeId[u] != treeId[v]) {
                mst.push_back(*it);
                total += it->w;
                p1 = treeId[u], p2 = treeId[v];
                for(int i = 0; i < n; ++i) {
                    if(treeId[i] == p2) treeId[i] = p1;
                }
            }
        }
    }
}
void solve(vector<vector<int>> &g) {
    int u, v;
    s.clear();
    for(const Edge &e : edges) {
        u = e.u, v = e.v;
        s.insert({min(u, v), max(u, v)});
    }
}
int main() {
    int x, y, t, id;
    string name1, name2;
    map<string, int> players;
    while(cin >> name1) {
        vector<vector<int>> g;
        if(name1 == "") {
            cin >> name1;
        }
        cin >> name2 >> t;
        players[name1] = id++;
        players[name2] = id;
    }
    return 0;
}