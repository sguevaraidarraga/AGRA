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

string makeString(queue<int> q, list<deque<int>> &l) {
    string ans(1000, ' ');
    string::iterator ct = ans.begin();
    while(!q.empty()) {
        if(q.front() != 10) {
            *ct = q.front() + '0';
        }
        else {
            *ct = '1';
            *(++ct) = '0';
        }
        q.pop();
        ct += 2;
    }
    *(++ct) = '|';
    ct+=2;
    for(list<deque<int>>::iterator it = l.begin(); it != l.end(); it++) {
        for(deque<int>::iterator jt = it->begin(); jt != it->end(); jt++) {
            if(*jt == 10) {
                *ct = '1';
                *(++ct) = '0';
            }
            else {
                *ct = *jt + '0';
            }
            ct += 2;
        }
    }
    return ans;
}
bool check(deque<int> &s, int a, int b, int c){return (s[a]+s[b]+s[c] == 10 || s[a]+s[b]+s[c] == 20 || s[a]+s[b]+s[c] == 30);}
int main() {
    int v, counter;
    bool f, f2;
    string currState;
    list<deque<int>>::iterator it;
    while(cin >> v && v != 0) {
        queue<int> deck;
        list<deque<int>> piles(7);
        set<string> gameStates;
        deck.push(v);
        for(int i = 1; i < 52; i++) {
            cin >> v;
            deck.push(v);
        }
        counter = 0;
        f2 = false;
        while(!piles.empty() && !f2) {
            it = piles.begin();
            while(it != piles.end() && !f2) {
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
                currState = makeString(deck, piles);
                if(piles.empty() && deck.size() == 52) {
                    cout << "Win : " << counter << endl;
                    f2 = true;
                }
                else if(deck.empty()) {
                    cout << "Loss: " << counter << endl;
                    f2 = true;
                }
                else if(gameStates.count(currState)) {
                    cout << "Draw: " << counter << endl;
                    f2 = true;
                }
                else {
                    gameStates.insert(currState);
                }
            }
        }
    }
    return 0;
}