/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem C - factorization
    Enero 22 de 2025
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef map<int, int> mii;

#define f(i, s, e) for(int i = s; i < e; i++)
#define rf(i, e, s) for(int i = e-1; i >= s; i--)
#define fit(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define rfit(it, v) for(auto it = v.rbegin(); it != v.rend(); it++)
#define pb push_back
#define mp make_pair

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define srt(v) sort(all(v))
#define sze(v) v.size()
#define len(s) s.lenght()

#define F first
#define S second

#define debug(x) cout << #x << ": " << endl;
#define op() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool inMat(vvi &m) {
    bool ans;
    f(i, 0, sze(m)) {

    }
    return ans;
}
vi factorize(int n, stack<int> &s, vvi &m) {
    vi ans;
    f(i, 2, n/2) {
        if(n%i == 0) {
            s.push(n/i);
            
        }
    }
    return ans;
}
int main() {
    op();
    int cases, n;
    stack<int> s;
    vvi data;
    vi tmp;
    while(cases--) {
        cin >> n;
        s.push(n);
        while(!s.empty()) {
            tmp = factorize(s.top(), s);
        }
    }
    return 0;
}