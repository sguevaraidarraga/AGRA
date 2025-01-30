/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem D - cakey
    Enero 29 de 2025
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Order {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        bool ans = false;
        if(a.second != b.second) {
            ans = a.second < b.second;
        }
        else if(a.first != b.first) {
            ans = a.first > b.first;
        }
        return ans;
    }
};
int main() {
    int n, m, val;
    map<int, int> data;
    map<int, int>::iterator it;
    while(cin >> n >> m && n != 0 && m != 0) {
        vector<int> nVal(n), mVal(m);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Order> pq;
        for(int i = 0; i < n; i++) {
            cin >> val;
            nVal[i] = val;
        }
        for(int i = 0; i < m; i++) {
            cin >> val;
            mVal[i] = val;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                val = mVal[j] - nVal[i];
                if(val >= 0) {
                    it = data.find(val);
                    if(it != data.end()) {
                        it->second++;
                    }
                    else {
                        data[val] = 1;
                    }
                }
            }
        }
        for(it = data.begin(); it != data.end(); it++) {
            pq.push(make_pair(it->first, it->second));
        }
        cout << pq.top().first << endl; 
        data.clear();
    }
    return 0;
}