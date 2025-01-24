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
    bool operator<(Card* &b) {
        bool ans = false;
        if(ocurrences != b->ocurrences) {
            ans = ocurrences < b->ocurrences;
        }
        else if(serial != b->serial) {
            ans = serial < b->serial;
        }
        else if(label != b->label) {
            ans = label > b->label;
        }
        return ans;
    }
};
int main() {
    int n, m, serial;
    string label;
    map<string, Card*> data;
    map<string, Card*>::iterator it;
    while(cin >> n >> m && n != 0 && m != 0) {
        priority_queue<Card*> pq;
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
            cout << pq.top()->label << ' ' << pq.top()->ocurrences << endl;
            pq.pop();
        }
        data.clear();
    }
    return 0;
}