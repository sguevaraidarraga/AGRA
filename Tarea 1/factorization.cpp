/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem C - factorization
    Enero 22 de 2025
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> factors(int n) {
    vector<int> ans;
    for(int i = 2; i < n/2; i++) {
        if(n%i == 0) {
            ans.push_back(i);
            ans.push_back(n/i);
        }
    }
    return ans;
}
void printVec(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}
int main() {
    int cases, n;
    while(cin >> cases && cases != 0) {
        stack<int> s;
        cin >> n;
        s.push(n);
        while(!s.empty()) {
            
        }
    }
    return 0;
}