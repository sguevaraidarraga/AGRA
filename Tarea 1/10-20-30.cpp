/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem A: 10-20-30
    Febrero 1 de 2025
*/

#include <iostream>
#include <queue>
#include <deque>

using namespace std;

#define debug(x) cout << #x << ": " << x << endl

bool check(deque<int> &s, int a, int b, int c){return (s[a]+s[b]+s[c] == 10 || s[a]+s[b]+s[c] == 20 || s[a]+s[b]+s[c] == 30);}
void play(queue<int> &q, deque<int> &s) {
    int n;
    bool f = false;
    while(s.size() >= 3 && !f) {
        n = s.size();
        if(check(s, 0, 1, n-1)) {
            q.push(s[0]);
            q.push(s[1]);
            q.push(s[n-1]);
            s.pop_front();
            s.pop_front();
            s.pop_back();
        }
        else if(check(s, 0, n-2, n-1)) {
            q.push(s[0]);
            q.push(s[n-2]);
            q.push(s[n-1]);
            s.pop_front();
            s.pop_back();
            s.pop_back();
        }
        else if(check(s, n-3, n-2, n-1)) {
            q.push(s[n-3]);
            q.push(s[n-2]);
            q.push(s[n-1]);
            s.pop_back();
            s.pop_back();
            s.pop_back();
        }
        else {
            f = true;
        }
    }
}
void printQ(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
void printV(vector<deque<int>> &v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int v, steps;
    bool f;
    while(cin >> v && v != 0) {
        queue<int> deck;
        vector<deque<int>> game(7);
        deck.push(v);
        for(int i = 1; i < 52; i++) {
            cin >> v;
            deck.push(v);
        }
        steps = 0;
        for(int i = 0; i < 14; i++) {
            (i < 7) ? v = i : v = i-7;
            game[v].push_back(deck.front());
            deck.pop();
            steps++;
        }
        f = false;
        while(game.size() != 0 && !f) {
            for(int i = 0; i < game.size() && !f; i++) {
                if(game[i].size() != 0) {
                    game[i].push_back(deck.front());
                    deck.pop();
                    steps++;
                    play(deck, game[i]);
                    if(deck.size() == 52) {
                        cout << "Win : " << steps << endl;
                        f = true;
                    }
                    else if(deck.empty()) {
                        cout << "Loss: " << steps << endl;
                        f = true;
                    }
                }
            }
        }
    }
    return 0;
}