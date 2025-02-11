/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B: triangle
    Febrero 10 de 2025
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long double solve(long double AB, long double ratio) {
    long double low = 0, high = AB, mid, c = AB*pow(ratio / (1.0L + ratio), 1/2);
    while(high-low > 1e-6) {
        mid = (low + high)/2;
        if(mid < c) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    cout << fixed << setprecision(6) << AB*pow(ratio / (1.0L + ratio), 1/2) << endl;
    return mid;
}
int main() {
    int T, AB, AC, BC, ratio, k = 1;
    cin >> T;
    while(T--) {
        cin >> AB >> AC >> BC >> ratio;
        cout << fixed << setprecision(6) << solve(AB, ratio) << endl;
        k++;
    }
    return 0;
}