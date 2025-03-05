/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem A: coaches
    Complejidad: O(nlog n + m)
    Marzo 3 de 2025
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Coach {
    string name;
    int birth, degree, generation;
    vector<int> coached;
    Coach() = default;
    Coach(string n, int y, int d) {
        name = n;
        birth = y;
        degree = d;
        generation = 0;
        coached = vector<int>();
    }
    bool operator<(const Coach &c) const {
        bool ans = false;
        if(generation != c.generation) {
            ans = generation < c.generation;
        }
        else if(coached.size() != c.coached.size()) {
            ans = coached.size() > c.coached.size();
        }
        else if(birth != c.birth) {
            ans = birth < c.birth;
        }
        else if(name != c.name) {
            ans = name < c.name;
        }
        return ans;
    }
};
void bfs(vector<Coach> &g) {
    int x, coach, coached;
    queue<int> q;
    for(int i = 0; i < g.size(); i++) {
        if(g[i].degree == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        x = q.front();
        q.pop();
        for(int i = 0; i < g[x].coached.size(); i++) {
            coached = g[x].coached[i];
            g[coached].generation = max(g[coached].generation, g[x].generation+1);
            g[coached].degree--;
            if(g[coached].degree == 0) {
                q.push(coached);
            }
        }
    }
}
int main() {
    int cases, n, m, y, c1, c2, currCase = 1, prevGen;
    string a, b;
    cin >> cases;
    for(int i = 1; i <= cases; i++) {
        cin >> n >> m;
        map<string, int> index;
        vector<Coach> g(n);
        for(int j = 0; j < n; j++) {
            cin >> a >> y;
            index[a] = j;
            g[j] = Coach(a, y, 0);
        }
        while(m--) {
            cin >> a >> b;
            c1 = index[a], c2 = index[b];
            g[c1].coached.push_back(c2);
            g[c2].degree++;
        }
        bfs(g);
        cout << "Scenario #" << i << ':' << endl;
        sort(g.begin(), g.end());
        prevGen = -1;
        for(int j = 0; j < g.size(); j++) {
            if(g[j].generation != prevGen && !g[j].coached.empty()) {
                prevGen = g[j].generation;
                cout << "Generation " << prevGen << ": " << g[j].name << endl;
            }
        }
        if(i != cases) {
            cout << endl;
        }
    }
    return 0;
}