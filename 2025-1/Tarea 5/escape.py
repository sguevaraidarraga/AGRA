"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B: escape
    Complejidad: O((n * m) * log(n * m))
    Abril 7 de 2025
"""

from sys import stdin
from heapq import heappush, heappop

n = m = int()
directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
direction = {'N': 0, 'E': 1, 'S': 2, 'W': 3}
opposite = {'N': 2, 'E': 3, 'S': 0, 'W': 1}

def dijkstra(g, c):
    global n, m
    dist = [[float("inf") for _ in range(m)] for _ in range(n)]
    pq = []
    heappush(pq, (0, n-1, 0))
    dist[n-1][0] = 0
    f = False
    while pq and not f:
        cd, cx, cy, = heappop(pq)
        if cx == 0 and cy == m-1:
            f = True
        else:
            if cd == dist[cx][cy]:
                for i in range(4):
                    nx, ny = cx + directions[i][0], cy + directions[i][1]
                    if 0 <= nx < n and 0 <= ny < m and g[nx][ny] != '#':
                        rotations = 0
                        if g[cx][cy] in "NESW":
                            rotations = min((i - direction[g[cx][cy]]) % 4, (direction[g[cx][cy]] - i) % 4)
                        if(g[nx][ny] == '.') or (g[nx][ny] in "NESW" and opposite[g[nx][ny]] == i):
                            nd = cd + (rotations * c[cx][cy]) + 1
                            if nd < dist[nx][ny]:
                                dist[nx][ny] = nd
                                heappush(pq, (nd, nx, ny))
    return cd if f else -1
def main():
    global n, m
    cases = int(stdin.readline())
    while cases:
        n, m = map(int, stdin.readline().split())
        g, c = [['.' for _ in range(m)] for _ in range(n)], [[1 for _ in range(m)] for _ in range(n)]
        d = []
        for i in range(n):
            l = stdin.readline().strip()
            for j in range(m):
                g[i][j] = l[j]
                if l[j] == '#':
                    c[i][j] = -1
                elif l[j] in "NESW":
                    d.append((i, j))
        l = stdin.readline().split()
        i = 0
        for x, y in d:
            c[x][y] = int(l[i])
            i += 1
        ans = dijkstra(g, c)
        print(ans if ans != -1 else "Poor Kianoosh")
        cases -= 1
main()