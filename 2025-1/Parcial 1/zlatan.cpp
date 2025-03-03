/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem A: zlatan
    Complejidad: O(10^4) debido a que hay 4 ruedas y cada una tiene 10 numeros posibles
    Marzo 2 de 2025
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

string S(4, '#');
string T(4, '#');
vector<bool> vis(10000, false);
int dir[] = {1, -1};

char sum(char c, int k) {
    char ans = c+k;
    if(ans < '0') ans = '9';
    else if(ans > '9') ans = '0';
    return ans;
}
int getIndx(string &s) {
    int ans = 0;
    for(int i = 0; i < s.size(); i++) ans = ans*10 + (s[i]-'0');
    return ans;
}
int bfs() {
    int ans = -1;
    int s = getIndx(S);
    if(!vis[s]) {
        int d;
        string cs, ns;
        queue<pair<string, int>> q;
        vis[s] = true;
        q.push({S, 0});
        bool f = false;
        while(!q.empty() && !f) {
            cs = q.front().first, d = q.front().second;
            q.pop();
            if(cs == T) {
                ans = d;
                f = true;
            }
            else {
                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j < 2; j++) {
                        ns = cs;
                        ns[i] = sum(cs[i], dir[j]);
                        s = getIndx(ns);
                        if(!vis[s]) {
                            vis[s] = true;
                            q.push({ns, d+1});
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int main() {
    int cases, n;
    string tmp(4, '#');
    cin >> cases;
    while(cases--) {
        for(int i = 0; i < 4; i++) cin >> S[i];
        for(int i = 0; i < 4; i++) cin >> T[i];
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 4; j++) cin >> tmp[j];
            vis[getIndx(tmp)] = true;
        }
        cout << bfs() << endl;
        fill(vis.begin(), vis.end(), false);
    }
    return 0;
}