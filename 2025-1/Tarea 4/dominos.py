"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B: dominos
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
def solve(g):
    global n, sccCnt
    tarjan(g)
    degree = [0] * sccCnt
    for i in range(n):
        for j in g[i]:
            if scc[i] != scc[j]:
                degree[scc[j]] += 1
    return sum(1 for i in range(sccCnt) if degree[i] == 0)
def main():
    global n
    cases = int(stdin.readline())
    while cases:
        n, m = map(int, stdin.readline().split())
        g = [[] for _ in range(n)]
        for _ in range(m):
            x, y = map(int, stdin.readline().split())
            g[x-1].append(y-1)
        print(solve(g))
        cases -= 1
main()