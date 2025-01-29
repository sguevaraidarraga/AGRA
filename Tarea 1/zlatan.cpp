/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem E - zlatan
    Enero 29 de 2025
*/

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Card {
    string label;
    int serial, ocurrences;
    Card(string lbl, int srl) {
        label = lbl;
        serial = srl;
        ocurrences = 1;
    }
    bool operator<(const Card &b) const {
        bool ans = false;
        if(ocurrences != b.ocurrences) {
            ans = ocurrences < b.ocurrences;
        }
        else if(serial != b.serial) {
            ans = serial < b.serial;
        }
        return ans;
    }
};
int main() {
    int n, m, serial;
    string label;
    map<string, Card> data;
    vector<Card> v;
    map<string, Card>::iterator it;
    while(cin >> n >> m && n != 0 && m != 0) {
        priority_queue<Card> pq;
        while(n--) {
            cin >> label >> serial;
            it = data.find(label);
            if(it != data.end()) {
                it->second.ocurrences++;
            }
            else {
                data.insert({label, Card(label, serial)});
            }
        }
        for(it = data.begin(); it != data.end(); it++) {
            pq.push(it->second);
        }
        for(int i = 0; i < m; i++) {
            v.push_back(pq.top());
            pq.pop();
        }
        sort(v.begin(), v.end(), [](const Card &a, const Card &b){return a.label < b.label;});
        for(vector<Card>::iterator jt = v.begin(); jt != v.end(); jt++) {
            cout << jt->label << ' ' << jt->ocurrences << endl;
        }
        data.clear();
        v.clear();
    }
    return 0;
}