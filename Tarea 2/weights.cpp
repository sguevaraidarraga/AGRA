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
    int l1 = -1, l2 = -1, cnt1 = 0, cnt2 = 0;
    bool f = true;
    for(int i = 0; i < r1.size() && f; i++) {
        if(r1[i] > w[mid]) {
            if(r1[i] != l1 && (cnt1 == 0 || cnt1 == 2)) {
                l1 = r1[i];
                cnt1 = 1;
            }
            else if(cnt1 < 2) {
                cnt1++;
            }
            else {
                f = false;
            }
        }
        if(r2[i] > w[mid]) {
            if(r2[i] != l2 && (cnt2 == 0 || cnt2 == 2)) {
                l2 = r2[i];
                cnt2 = 1;
            }
            else if(cnt2 < 2) {
                cnt2++;
            }
            else {
                f = false;
            }
        }
    }
    return f;
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