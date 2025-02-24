"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B: forest
    Febrero 24 de 2025
"""

from sys import stdin
from collections import deque
from heapq import heappush, heappop

directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

class Tree:
    def __init__(self, specie, height):
        self.specie = specie
        self.height = height
        self.visited = False
    def __lt__(self, b):
        ans = False
        if self.specie != b.specie:
            ans = self.specie < b.specie
        elif self.height != b.height:
            ans = self.height < b.height
        return ans
    def __str__(self):
        return f"({self.specie}, {self.height}, {self.visited})"
    def __repr__(self):
        return self.__str__()
def bfsAux(g, x, y):
	ans = g[x][y].height
	q = deque()
	q.append((x, y))
	g[x][y].visited = True
	while len(q) != 0:
		i, j = q.popleft()
		#print(g[i][j])
		for dx, dy in directions:
			nx, ny = i + dx, j + dy
			#print(nx, ny)
			if 0 <= nx < len(g) and 0 <= ny < len(g[0]) and g[nx][ny].specie == g[x][y].specie and not g[nx][ny].visited:
				q.append((nx, ny))
				g[nx][ny].visited = True
				ans = max(ans, g[nx][ny].height)
	return ans
def bfs(g):
	for i in range(len(g)):
		for j in range(len(g[0])):
			if not g[i][j].visited:
				ans = bfsAux(g, i, j)
				print(f"{g[i][j].specie} {ans}")
def main():
	cases = int(stdin.readline())
	currCase = 1
	while cases:
		n, m = map(int, stdin.readline().split())
		forest = []
		pq = []
		for i in range(n):
			tmp = []
			line = stdin.readline().split()
			for j in line:
				specie, height = j.split('#')
				tmp.append(Tree(specie, height))
			forest.append(tmp)
		print(f"Forest #{currCase}")
		bfs(forest)
		print(forest)
		currCase += 1
		cases -= 1
main()