"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem C: money
    Febrero 25 de 2025
"""

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, a, b;
	while(cin >> n) {
		vector<vector<int>> data(n, vector<int>());
		for(int i = 0; i < n; i++) {
			cin >> a >> b;
			data[i].push_back(a);
			data[i].push_back(b);
		}
	}
	return 0;
}