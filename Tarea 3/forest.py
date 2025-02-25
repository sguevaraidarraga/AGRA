"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B: forest
    Febrero 25 de 2025
"""

from sys import stdin
from collections import deque
from heapq import heappush, heappop

directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def bfsAux(g, vis, x, y):
	ans = g[x][y][1]
	q = deque()
	vis[x][y] = True
	q.append((x, y))
	while len(q) > 0:
		cx, cy = q.popleft()
		for dx, dy in directions:
			nx, ny = cx + dx, cy + dy
			if 0 <= nx < len(g) and 0 <= ny < len(g[0]) and not vis[nx][ny] and g[nx][ny][0] == g[cx][cy][0]:
				vis[nx][ny] = True
				q.append((nx, ny))
				ans = max(ans, g[nx][ny][1])
	return ans
def bfs(g):
	ans = []
	vis = [[False for _ in range(len(g[0]))] for _ in range(len(g))]
	for i in range(len(g)):
		for j in range(len(g[0])):
			if not vis[i][j]:
				v = bfsAux(g, vis, i, j)
				ans.append((g[i][j][0], v))
	return ans
def main():
	cases = int(stdin.readline())
	currCase = 1
	while cases:
		n, m = map(int, stdin.readline().split())
		forest = []
		for i in range(n):
			tmp = []
			line = stdin.readline().split()
			for j in line:
				specie, height = j.split('#')
				tmp.append((specie, int(height)))
			forest.append(tmp)
		print(f"Forest #{currCase}")
		data = bfs(forest)
		data.sort(key=lambda x: (x[0], x[1]))
		for specie, height in data:
			print(f"{specie} {height}")
		currCase += 1
		cases -= 1
main()