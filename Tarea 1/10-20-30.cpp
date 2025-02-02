/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem A: 10-20-30
    Febrero 2 de 2025
*/

#include <iostream>
#include <queue>
#include <list>
#include <deque>
#include <set>
#include <string>

using namespace std;

#define debug(x) cout << #x << ": " << x << endl

void printQ(queue<int> &q) {
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
void printL(list<deque<int>> &l) {
    for(list<deque<int>>::iterator it = l.begin(); it != l.end(); it++) {
        cout << "[";
        for(int j = 0; j < it->size(); j++) {
            cout << (*it)[j];
            if(j != it->size()-1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    cout << endl;
}
string makeString(queue<int> &q) {
    string ans(100, ' ');
    string::iterator it = ans.begin();
    while(!q.empty()) {
        *it = q.front() + '0';
        q.pop();
        it += 2;
    }
    return ans;
}
bool check(deque<int> &s, int a, int b, int c){return (s[a]+s[b]+s[c] == 10 || s[a]+s[b]+s[c] == 20 || s[a]+s[b]+s[c] == 30);}
int main() {
    int v, i, counter;
    bool f, f2;
    list<deque<int>>::iterator it;
    while(cin >> v && v != 0) {
        queue<int> deck;
        list<deque<int>> piles(7);
        set<string> gameStates;
        deck.push(v);
        for(i = 1; i < 52; i++) {
            cin >> v;
            deck.push(v);
        }
        cout << makeString(deck) << endl;
        i = 0;
        counter = 0;
        f2 = false;
        while(!piles.empty()) {
            it = piles.begin();
            while(it != piles.end()) {
                it->push_back(deck.front());
                deck.pop();
                counter++;
                f = false;
                while(it->size() >= 3 && !f) {
                    if(check((*it), 0, 1, it->size()-1)) {
                        deck.push((*it)[0]), deck.push((*it)[1]), deck.push((*it)[it->size()-1]);
                        it->pop_front(), it->pop_front(), it->pop_back();
                    }
                    else if(check((*it), 0, it->size()-2, it->size()-1)) {
                        deck.push((*it)[0]), deck.push((*it)[it->size()-2]), deck.push((*it)[it->size()-1]);
                        it->pop_front(), it->pop_back(), it->pop_back();
                    }
                    else if(check((*it), it->size()-3, it->size()-2, it->size()-1)) {
                        deck.push((*it)[it->size()-3]), deck.push((*it)[it->size()-2]), deck.push((*it)[it->size()-1]);
                        it->pop_back(), it->pop_back(), it->pop_back();
                    }
                    else {
                        f = true;
                    }
                }
                (it->empty()) ? it = piles.erase(it) : it++;
                if(piles.empty()) {
                    cout << "Win : " << counter << endl;
                    f2 = true;
                }
                else if(deck.empty()) {
                    cout << "Loss: " << counter << endl;
                    f2 = true;
                }
            }
            i++;
        }
    }
    return 0;
}