"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem D: shipping
    Febrero 26 de 2025
"""

from sys import stdin
from collections import deque

# Shipment cost = (size of the shipment) * (# of shipping legs required)

def bfs(g, a, b):
    vis = [False for _ in range(len(g))]
    q = deque()
    vis[a] = True
    q.append((a, 0))
    f = False
    while len(q) > 0 and not f:
        v, d = q.popleft()
        if v == b:
            f = True
        else:
            for i in g[v]:
                if not vis[i]:
                    vis[i] = True
                    q.append((i, d+1))
    return d if f else -1
def main():
    st = int(stdin.readline())
    print("SHIPPING ROUTES OUTPUT")
    for s in range(st):
        print(f"\nDATA SET {s+1}\n")
        m, n, p = map(int, stdin.readline().split())
        mp = {}
        g = [[] for _ in range(m)]
        wh = stdin.readline().split()
        for i in range(m):
            mp[wh[i]] = i
        for i in range(n):
            a, b = stdin.readline().split()
            g[mp[a]].append(mp[b])
            g[mp[b]].append(mp[a])
        for i in range(p):
            size, a, b = stdin.readline().split()
            legs = bfs(g, mp[a], mp[b])
            if legs != -1:
                cost = int(size) * legs
                print(f"${cost * 100}")
            else:
                print("NO SHIPMENT POSSIBLE")
    print("\nEND OF OUTPUT")
main()