/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B: triangle
    Febrero 4 de 2025
*/

#include <iostream>
#include <cmath>

using namespace std;

#define debug(x) cout << #x << ": " << x << endl

void solve(double AB, double ratio) {
    // AD - AB * sqrt(ratio/(1+ratio))
    double low = 0, high = AB, mid;
    while(high-low > 1e-6) {
        mid = (low + high)/2;
        if(low*mid < 0) {
            mid = low;
        }
        else if(high*mid < 0) {
            mid = high;
        }
    }
    cout << mid << endl;
}
int main() {
    int T, AB, AC, BC, ratio;
    cin >> T;
    while(T--) {
        cin >> AB >> AC >> BC >> ratio;
        solve(AB, ratio);
    }
    return 0;
}