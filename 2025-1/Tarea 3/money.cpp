/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem C: money
    Complejidad: O()
    Marzo 4 de 2025
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

void dfsAux(vector<vector<int>> &g, vector<int> &state, string &ans, int k) {
	stack<int> s;
	vector<int> parent(g.size(), -1);
	s.push(k);
	while(!s.empty()) {
		int x = s.top();
		if(state[x] == 0) {
			state[x] = 1;
			for(int cx : g[x]) {
				if(state[cx] == 0) {
					parent[cx] = x;
					s.push(cx);
				}
				else if(state[cx] == 1) {
					int nx = x;
                    while(nx != -1) {
                        ans[nx] = 'N';
                        nx = parent[nx];
                    }
				}
			}
		}
		else {
			state[x] = 2;
			for(int cx : g[x]) {
                if(ans[cx] == 'N') ans[x] = 'N';
            }
			s.pop();
		}
	}
}
string dfs(vector<vector<int>> &g) {
	string ans(g.size(), 'Y');
	vector<int> state(g.size(), 0);
	for(int i = 0; i < g.size(); i++) {
		if(state[i] == 0) dfsAux(g, state, ans, i);
	}
	return ans;
}
int main() {
	int n, a, b;
	while(cin >> n) {
		vector<vector<int>> g(n);
		for(int i = 0; i < n; i++) {
			cin >> a >> b;
			g[i].push_back(--a);
			g[i].push_back(--b);
		}
		cout << dfs(g) << endl;
	}
	return 0;
}