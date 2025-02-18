/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem C: weights
    Febrero 14 de 2025
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define debug(x) cout << #x << ": " << x << endl

bool organize(vector<int> &w, vector<int> &r1, vector<int> &r2, int mid) {
    int lst1 = 0, lst2 = 0;
    bool f = true;
    for(int i = 0; i < r1.size() && f; i++) {
        if(r1[i] > w[mid]) {
            if(lst1 == 0) {
                lst1 = r1[i];
            }
            else if(lst1 == r1[i]) {
                lst1 = 0;
            }
            else {
                f = false;
            }
        }
        if(r2[i] > w[mid]) {
            if(lst2 == 0) {
                lst2 = r2[i];
            }
            else if(lst2 == r2[i]) {
                lst2 = 0;
            }
            else {
                f = false;
            }
        }
    }
    return f && lst1 == 0 && lst2 == 0;
}
void solve(vector<int> &w, vector<int> &r1, vector<int> &r2) {
    int low = 0, high = w.size()-1, mid;
    while(low < high) {
        mid = (low+high)/2;
        if(organize(w, r1, r2, mid)) {
            high = mid;
        }
        else {
            low = mid+1;
        }
    }
    cout << w[low] << endl;
}
int main() {
    int n;
    while(cin >> n) {
        set<int> s;
        vector<int> rack1(n), rack2(n);
        s.insert(0);
        for(int i = 0; i < n; i++) {
            cin >> rack1[i];
            s.insert(rack1[i]);
        }
        for(int i = 0; i < n; i++) {
            cin >> rack2[i];
            s.insert(rack2[i]);
        }
        vector<int> weights(s.begin(), s.end());
        solve(weights, rack1, rack2);
    }
    return 0;
}