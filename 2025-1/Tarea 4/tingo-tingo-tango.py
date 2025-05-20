"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem A: tingo-tingo-tango
    Complejidad: O(V + E)
    Marzo 25 de 2025
"""

from sys import stdin, setrecursionlimit
from collections import deque

setrecursionlimit(2000)
UNVISITED = -1

def dfs(g, at):
    global t, sccCnt
    stack.append(at)
    onStack[at] = True
    tVis[at] = low[at] = t
    t += 1
    for to in g[at]:
        if tVis[to] == UNVISITED:
            dfs(g, to)
            low[at] = min(low[at], low[to])
        elif onStack[to]:
            low[at] = min(low[at], tVis[to])
    if tVis[at] == low[at]:
        f = False
        while stack and not f:
            node = stack.pop()
            onStack[node] = False
            scc[node] = sccCnt
            if node == at:
                f = True
        sccCnt += 1
def tarjan(g):
    global n, t, scc, tVis, low, stack, onStack, sccCnt
    scc, tVis, low = [UNVISITED] * n, [UNVISITED] * n, [UNVISITED] * n
    stack, onStack = deque(), [False] * n
    t, sccCnt = 0, 0
    for i in range(n):
        if tVis[i] == UNVISITED:
            dfs(g, i)
def bfs(g, a, b):
    vis = [False for _ in range(len(g))]
    q = deque()
    vis[a] = True
    q.append((a, 0))
    f = False
    while q and not f:
        v, d = q.popleft()
        if v == b:
            f = True
        else:
            for i in g[v]:
                if not vis[i]:
                    vis[i] = True
                    q.append((i, d+1))
    return d if f else -1
def solve(g, a, b):
    global n, sccCnt
    tarjan(g)
    gC = [[] for _ in range(sccCnt)]
    for i in range(n):
        for j in g[i]:
            if scc[i] != scc[j]:
                gC[scc[i]].append(scc[j])
    return bfs(gC, scc[a], scc[b])
def main():
    global n
    n, m = map(int, stdin.readline().split())
    while n != 0 and m != 0:
        z, x = map(int, stdin.readline().split())
        g = [[] for _ in range(n)]
        for _ in range(m):
            p, q = map(int, stdin.readline().split())
            g[p-1].append(q-1)
        print(f"Zlatan will need the object to pass through {solve(g, z-1, x-1)} groups.")
        n, m = map(int, stdin.readline().split())
main()