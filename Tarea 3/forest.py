"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B: forest
    Febrero 20 de 2025
"""

from sys import stdin
from collections import deque
from heapq import heappush, heappop

class Tree:
    def __init__(self, specie, height):
        self.specie = specie
        self.height = height
    def __lt__(self, b):
        ans = False
        if self.specie != b.specie:
            ans = self.specie < b.specie
        elif self.height != b.height:
            ans = self.height < b.height
        return ans
def bfs(i, j, forest, visited):
	q = deque()
	q.append(i)
	visited[i] = True
	while len(q) != 0:
		top = q.popleft()
		for k in forest[top]:
			if not visited[i][k]:
				visited[i][k] = True
				q.append(j)
def search(forest):
	n, m = len(forest), len(forest[0])
	visited = [[False for _ in range(m)] for _ in range(n)]
	for i in range(n):
		for j in range(m):
			if not visited[i][j]:
				bfs(i, j, forest, visited)
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
		currCase += 1
		cases -= 1
main()