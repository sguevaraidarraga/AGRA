/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem A - The Pursuit of Happyness: South Park-AGRA Version
    Complejidad: O(d * (n + m))
    Mayo 20 de 2025
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX_CITIES 801
#define MAX_DAYS 10000
#define UNVISITED -1

#define debug(x) cout << #x << ": " << endl

using namespace std;

int n;

struct Triple {
    int first, second, third;
    Triple(int f, int s, int t) : first(f), second(s), third(t) {}
    bool operator<(const Triple &b) const {return second > b.second;}
};
int dijkstra(vector<vector<pair<int, int>>> &g, vector<int> &salary, int s, int e, int k) {
    int ans = UNVISITED, at, days, money, to, ticket;
    bool f = false;
    vector<vector<int>> dist(n+1, vector<int>(MAX_DAYS, UNVISITED));
    priority_queue<Triple> pq;
    pq.push({k, 0, s});
    dist[s][0] = k;
    while(!pq.empty() && !f) {
        money = pq.top().first, days = pq.top().second, at = pq.top().third;
        pq.pop();
        if(at == e) {
            ans = days;
            f = true;
        }
        if(dist[at][days] == money) {
            if(days+1 < MAX_DAYS && dist[at][days+1] < money+salary[at]) {
                dist[at][days+1] = money+salary[at];
                pq.push({money+salary[at], days+1, at});
            }
            for(int i = 0; i < g[at].size(); i++) {
                to = g[at][i].first, ticket = g[at][i].second;
                if(money >= ticket && dist[to][days] < money-ticket) {
                    dist[to][days] = money-ticket;
                    pq.push({money-ticket, days, to});
                }
            }
        }
    }
    return ans;
}
int main() {
    int t, m, p, r, s, e, a, b, c, ans;
    cin >> t;
    while(t--) {
        cin >> n >> m >> p >> r;
        vector<vector<pair<int, int>>> g(n+1);
        vector<int> salary(n+1);
        for(int i = 1; i <= n; i++) cin >> salary[i];
        cin >> s >> e;
        while(m--) {
            cin >> a >> b >> c;
            g[a].push_back({b, c});
        }
        ans = dijkstra(g, salary, s, e, p-r);
        if(ans == UNVISITED) cout << "Sorry Kenny, Happiness is not for you :(" << endl; 
        else cout << "Kenny happiness will cost " << ans << " days of work :)" << endl;
    }
    return 0;
}