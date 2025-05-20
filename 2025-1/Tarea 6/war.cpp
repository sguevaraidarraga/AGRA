#include <iostream>
#include <vector>

#define debug(x) cout << #x << ": " << x << endl

using namespace std;

class DisjointSet {
    vector<int> parent, enemy, size;

    public:
        DisjointSet(int n) {
            parent.resize(n);
            enemy.resize(n, -1);
            size.resize(n, 0);
            for(int i = 0; i < n; i++) parent[i] = i;
        }
        void makeSet(int x) {
            parent[x] = x;
            size[x] = 0;
        }
        int find(int x) {
            if(parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        void unionSet(int x, int y) {
            x = find(x), y = find(y);
            if(x != y) {
                if(size[x] < size[y]) swap(x, y);
                parent[y] = x;
                if(size[x] == size[y]) size[x]++;
            }
        }
        bool setFriends(int x, int y) {
            bool ans = true;
            int px = find(x), py = find(y);
            if(px != enemy[py]) {
                unionSet(px, py);
                ans = false;
            }
            return ans;
        }
        bool setEnemies(int x, int y) {
            bool ans = true;
            int px = find(x), py = find(y);
            if(px != py) {
                if(enemy[px] == -1) enemy[px] = py;
                else unionSet(enemy[px], py);
                if(enemy[py] == -1) enemy[py] = px;
                else unionSet(px, enemy[py]);
                ans = false;
            }
            return ans;
        }
        bool areFriends(int x, int y) {
            return find(x) == find(y);
        }
        bool areEnemies(int x, int y) {
            int px = find(x) , py = find(y);
            return enemy[px] == py;
        }
        void print() {
            cout << "P: [";
            for(int i = 0; i < parent.size(); i++) {
                cout << parent[i];
                if(i != parent.size()-1) {
                    cout << ", ";
                }
            }
            cout << ']'<< endl << "E: [";
            for(int i = 0; i < enemy.size(); i++) {
                cout << enemy[i];
                if(i != enemy.size()-1) {
                    cout << ", ";
                }
            }
            cout << ']'<< endl << "S: [";
            for(int i = 0; i < size.size(); i++) {
                cout << size[i];
                if(i != size.size()-1) {
                    cout << ", ";
                }
            }
             cout << ']'<< endl;
        }
};
int main() {
    int n, c, x, y, ans;
    while(cin >> n) {
        cout << n << endl;
        DisjointSet ds(n);
        while(cin >> c >> x >> y) {
        cout << c << ' ' << x << ' ' << y << endl;
        if(c == 0 && x == 0 && y == 0) break;
        ans = 2;
        switch(c) {
            case 1:
                if(ds.setFriends(x, y)) ans = -1;
                break;
            case 2:
                if(ds.setEnemies(x, y)) ans = -1;
                break;
            case 3:
                ans = ds.areFriends(x, y);
                break;
            case 4:
                ans = ds.areEnemies(x, y);
                break;
        }
        if(ans != 2) cout << ans << endl;
        ds.print();
        }
    }
}