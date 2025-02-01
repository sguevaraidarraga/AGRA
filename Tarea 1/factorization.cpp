/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem C - factorization
    Enero 30 de 2025
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Triple {
    int num, it;
    vector<int> factors;
    Triple(int n) {
        num = n;
        it = 2;
        factors = vector<int>();
    }
    Triple(int n, vector<int> &v) {
        num = n;
        it = v.empty() ? 2 : v[v.size()-1];
        factors = v;
    }
};
vector<vector<int>> factorize(int k) {
    int n, *i;
    stack<Triple> s;
    vector<vector<int>> ans;
    s.push(Triple(k));
    Triple *t;
    while(!s.empty()) {
        t = &s.top(), n = t->num, i = &t->it;
        if((*i) * (*i) <= n) {
            if(n%(*i) == 0) {
                vector<int> aux = s.top().factors;
                aux.push_back(*i);
                s.push(Triple(n/(*i), aux));
            }
            (*i)++;
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
            cout << m[i][j];
            if(j != m[i].size()-1) {
                cout << ' ';
            }
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