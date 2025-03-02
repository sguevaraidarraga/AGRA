#include <iostream>

using namespace std;

int main() {
    int ans, s, w, c, k, m;
    while(cin >> s >> w >> c >> k >> m) {
        ans = (10000/c)*(2*s + w)+(k*m);
        cout << ans << endl;
    }
    return 0;
}