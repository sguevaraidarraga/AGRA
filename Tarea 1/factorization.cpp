/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem C - factorization
    Enero 29 de 2025
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct Triple {
    int num;
    vector<int> factors;
    Triple(int n) {
        num = n;
        factors = vector<int>();
    }
    Triple(int n, vector<int> &v) {
        num = n;
        factors = v;
    }
};
vector<vector<int>> factorize(int k) {
    int n, i = 2;
    stack<Triple> s;
    vector<vector<int>> ans;
    s.push(Triple(k));
    Triple *t;
    while(!s.empty()) {
        t = &s.top(), n = t->num;
        if(i < n/i) {
            if(n%i == 0) {
                vector<int> aux = s.top().factors;
                aux.push_back(i);
                s.push(Triple(i/n, aux));
            }
            i++;
        }
        else {
            if(k != n) {
                t->factors.push_back(n);
                ans.push_back(t->factors);
            }
            s.pop();
        }
    }
    return ans;
}
void printMat(const vector<vector<int>> &m) {
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}
int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<vector<int>> data = factorize(n);
        cout << data.size() << endl;
        printMat(data);
    }
    return 0;
}