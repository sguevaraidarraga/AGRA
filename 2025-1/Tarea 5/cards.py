"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem A: cards
    Complejidad: O((p + q)log p)
    Abril 3 de 2025
"""

from sys import stdin
from heapq import heappush, heappop

def dijkstra(g):
    dist = [float('inf') for _ in range(len(g))]
    pq = []
    heappush(pq, (0, 1))
    dist[1] = 0
    while len(pq) != 0:
        du, u = heappop(pq)
        if du <= dist[u]:
            for v, duv in g[u]:
                if du+duv < dist[v]:
                    dist[v] = du+duv
                    heappush(pq, (dist[v], v))
    return sum(dist[2:])
def main():
    cases = int(stdin.readline())
    while cases:
        p, q = map(int, stdin.readline().split())
        g, gt = [[] for _ in range(p+1)], [[] for _ in range(p+1)]
        for _ in range(q):
            a, b, d = map(int, stdin.readline().split())
            g[a].append((b, d))
            gt[b].append((a, d))
        print(dijkstra(g) + dijkstra(gt))
        cases -= 1
main()