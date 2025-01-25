/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem E - zlatan
    Enero 24 de 2025
*/

#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct Card {
    string label;
    int serial, ocurrences;
    Card(string lbl, int srl) {
        label = lbl;
        serial = srl;
        ocurrences = 1;
    }
};
struct Order {
    bool operator()(Card* &a, Card* &b) {
        bool ans = false;
        if(a->ocurrences != b->ocurrences) {
            ans = a->ocurrences < b->ocurrences;
        }
        else if(a->serial != b->serial) {
            ans = a->serial < b->serial;
        }
        else if(a->label != b->label) {
            ans = a->label > b->label;
        }
        return ans;
    }
};
int main() {
    int n, m, serial;
    string label;
    map<string, Card*> data;
    vector<Card*> v;
    map<string, Card*>::iterator it;
    while(cin >> n >> m && n != 0 && m != 0) {
        priority_queue <Card*, vector<Card*>, Order> pq;
        while(n--) {
            cin >> label >> serial;
            it = data.find(label);
            if(it != data.end()) {
                it->second->ocurrences++;
            }
            else {
                data[label] = new Card(label, serial);
            }
        }
        for(it = data.begin(); it != data.end(); it++) {
            pq.push(it->second);
        }
        for(int i = 0; i < m; i++) {
            v.push_back(pq.top());
            pq.pop();
        }
        for(vector<Card*>::reverse_iterator jt = v.rbegin(); jt != v.rend(); jt++) {
            cout << (*jt)->label << ' ' << (*jt)->ocurrences << endl;
        }
        data.clear();
        v.clear();
    }
    return 0;
}