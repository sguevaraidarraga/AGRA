"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B: forest
    Febrero 20 de 2025
"""

from sys import stdin
from collections import deque

def search(forest, visited):
	q = deque()
	while len(q) != 0:
		
def main():
	cases = int(stdin.readline())
	while cases:
		n, m = map(int, stdin.readline().split())
		forest = deque()
		visited = deque([deque([False for _ in range(m)]) for _ in range(n)])
		i = 0
		for i in range(n):
			tmp = deque()
			line = stdin.readline().split()
			for j in line:
				specie, height = j.split('#')
				tmp.append((specie, int(height)))
			forest.append(tmp)
		#print(forest)
		cases -= 1
main()