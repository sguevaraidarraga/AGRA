/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B: bit
    Febrero 14 de 2025
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define debug(x) cout << #x << ": " << x << endl

void printVec(vector<int> &v, int s, int e) {
    cout << "Vector: [";
    for(int i = s; i <= e; i++) {
        cout << v[i];
        if(i != e) {
            cout << ", ";
        }
    }
    cout << ']' << endl;
}
void solve(vector<int> &weights, vector<int> &racks) {
    int last, cnt, low = 0, high = weights.size()-1, mid;
    bool f;
    while(low < high) {
        //printVec(weights, low, high);
        mid = (low+high)/2;
        last = 0, cnt = 0,  f = true;
        for(int i = 0; i < racks.size() && f; i++) {
            if(racks[i] > weights[mid]) {
                if(racks[i] != last && (cnt == 0 || cnt == 2)) {
                    last = racks[i];
                    cnt = 1;
                }
                else if(cnt < 2) {
                    cnt++;
                }
                else {
                    f = false;
                }
            }
        }
        if(f) {
            high = mid;
        }
        else {
            low = mid+1;
        }
    }
    cout << weights[low] << endl;
}
int main() {
    int n, v;
    while(cin >> n) {
        set<int> s;
        vector<int> racks(2*n), weights;
        s.insert(0);
        for(int i = 0; i < racks.size(); i++) {
            cin >> v;
            racks[i] = v;
            s.insert(v);
        }
        for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
            weights.push_back(*it);
        }
        //printVec(l, 0, l.size()-1);
        solve(weights, racks);
    }
    return 0;
}